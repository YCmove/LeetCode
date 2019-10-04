#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void print_vec(vector<int> & v){
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

// 有通過Leetcode
class Solution_B {
public:
vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) 
{
    vector<int> result;
    vector<int> indegree(numCourses, 0);
    queue<int> Q;
    vector<vector<int> > G(numCourses, vector<int>());    
    
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int x = prerequisites[i][0];
        int y = prerequisites[i][1];
        G[y].push_back(x);
        indegree[x]++;
    }
    
    for (int node = 0; node < numCourses; node++)
    {
        if (indegree[node] == 0)
            Q.push(node);
    }
    
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        result.push_back(x);
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i];
            indegree[y]--;
            if (indegree[y] == 0)
            {
                Q.push(y);
            }
        }
    }
    if (result.size() < numCourses)
        result.clear();
        
    return result;    
}
};




// 有通過Leetcode
class Solution_A {
public:
    vector<int> findOrder(int num, vector<vector<int> >& pres) {
        vector<vector<int>> graph(num);
        vector<int> indegrees(num, 0), v;
        stack<int> toVisit;
        int count = 0;
        // for(auto& pair: pres)
        // {
        //     graph[pair.second].push_back(pair.first);
        //     indegrees[pair.first]++;
        // }
        for (auto it = pres.begin(); it != pres.end(); it++){
            graph[it->back()].push_back(it->front());
            indegrees[it->front()]++;
        }
        for(int i = 0; i < num; i++)
            if(!indegrees[i]) toVisit.push(i);
        while(!toVisit.empty())
        {
            int from = toVisit.top();
            toVisit.pop();
            for(auto n: graph[from])
                if(--indegrees[n] == 0) toVisit.push(n);
            count++;
            v.push_back(from);
        }
        return count==num? v : (v.clear(), v);
    }
};



// 有通過Leetcode
class Solution {
public:
    // int findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // cout << "numCourses: " << numCourses << endl;
        // mapping  prerequisites to graph
        // 初始化時，numCourses不用減一！！ n個就是n個
        vector<vector<int> > graph(numCourses, vector<int>());
        // 要回傳的vector
        vector<int> v;
        // graph 有每個點的資訊，紀錄每個點的out-degree有哪些點
        for (auto it = prerequisites.begin(); it != prerequisites.end(); it++){
            // it->back(): 是 start node
            // it->front(): 是 end node
            graph[it->back()].push_back(it->front());
        }

        // print_vec(graph[0]);
        // print_vec(graph[1]);
        // print_vec(graph[2]);
        // print_vec(graph[3]);
        // print_vec(graph[4]);

        // in-degree table
        vector<int> indegree(numCourses, 0); // 每個點都有在裡面
        for (auto it = prerequisites.begin(); it != prerequisites.end(); it++){
            // it->back(): 是 start node
            // it->front(): 是 end node
            indegree[it->front()]++; // 代表這個點有in-degree
        }


        // DFS use Stack
        stack<int> to_visited;
        // 初始化stack, 從root nodes開始DFS, 利用in-degree找root node
        for (auto it = indegree.begin(); it != indegree.end(); it++){
            int curr = distance(indegree.begin(), it);
            if (*it == 0){ // 0 is false, 1 is true
                to_visited.push(curr); // curr is the root node
                // cout << "root nodes: " << curr << endl;
            }
        }
        
        int counter = 0;
        while (!to_visited.empty()){
            int curr = to_visited.top();
            to_visited.pop();
            v.push_back(curr);
            counter ++;

            // 找 curr的out-degree鄰居
            // for (auto it = graph[curr].begin(); it != graph[curr].end(); it++){
            
            // 比較簡潔的寫法
            for (auto n: graph[curr]){
                // cout << "n = " << n << endl;
                indegree[n]--;
                if (indegree[n] == 0){
                    // cout << "1. to_visited.size()=" << to_visited.size() << endl;
                    to_visited.push(n);
                }
                // cout << "2. to_visited.size()=" << to_visited.size() << endl;
                // cout << "--------" << endl;
            }
        }

        if (counter == numCourses){
            cout << "1. " << endl;
            return v;
        } else {
            cout << "2. " << endl;
            return (v.clear(), v);
        }
        // print_vec(v);
        // return 0;
    }
};


int main(){
    // Solution_A s;
    Solution_B s;
    // Solution s;

    // vector<int> v1({1, 0}); // 0 -> 1
    // vector<int> v2({2, 0}); // 0 -> 2
    // vector<int> v3({3, 1}); // 1 -> 3
    // vector<int> v4({3, 2}); // 2-> 3
    // vector<vector<int> > vec({v1, v2, v3, v4});
    // vector<int> result = s.findOrder(4, vec);

    // vector<int> v1({1, 0}); // 0 -> 1
    // vector<vector<int> > vec({v1});
    // vector<int> result = s.findOrder(2, vec);

    vector<int> v3({3, 2});
    vector<int> v2({2, 0});
    vector<int> v1({4, 0});
    vector<int> v4({1, 0});
    vector<vector<int> > vec({v1, v2, v3, v4});
    vector<int> result = s.findOrder(5, vec);

    // vector<int> v1({});
    // vector<int> v2({});
    // vector<int> v3({});
    // vector<int> v4({});
    // vector<vector<int> > vec({v1, v2, v3, v4, v5});
    // vector<int> result = s.findOrder(5, vec);

    print_vec(result);

    return 0;
}

