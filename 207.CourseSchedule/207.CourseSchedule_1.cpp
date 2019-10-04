#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        return 0;
    }
};


int main(){
    Solution s;

    vector<int> v1({1, 0});
    vector<int> v2({0, 1});
    vector<vector<int> > vec({v1, v2});

    cout << s.canFinish(2, vec) << endl;

    return 0;
}

