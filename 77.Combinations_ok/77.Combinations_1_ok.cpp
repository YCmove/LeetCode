#include <iostream>
#include <vector>

using namespace std;

// reference: https://leetcode.com/problems/combinations/discuss/27081/C%2B%2B-concise-recursive-solution-C(nk)-greaterC(n-1k-1)-8ms

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> temp; // 一組n個的 組合之一

        combine(1, n, k, temp, ans);

        return ans;
    }

private:
    void combine(int begin, int n, int k, vector<int> & temp, vector<vector<int> > & ans){

        // k 減到 0時, 代表 組合temp已經塞滿, 回傳 temp
        if (k == 0){
            ans.push_back(temp);
            return;
        }

        // cout << "n: " << n << " / k: " << k << endl;
        // n: 輸入總數; k: 選擇k個
        for (int i = begin; n - i + 1 >= k; i++){
            // cout << "i: " << i << endl;
            temp.push_back(i);
            // n: 輸入總數; k: 選擇k個
            combine(i+1, n, k - 1, temp, ans);
            temp.pop_back();
        }

    }
};

void print_vec(vector<vector<int> > vec){
    int size = vec.size();
    cout << "size: " << size << endl;
    for (int i = 0; i < size; i++){
        cout << "[ ";
        for (auto it = vec[i].begin(); it != vec[i].end(); it++){
            cout << *it << " ";
        }
        cout << "]";
    }
}


int main(){

    int n, k;
    vector<vector<int> > vec;
    Solution s;

    n = 4; // total 1, 2, 3, 4
    k = 2; // n: 輸入總數; k: 選擇k個

    vec = s.combine(n, k);
    print_vec(vec);
    // cout <<  << endl;

    return 0;
}