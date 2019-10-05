#include <iostream>
#include <vector>

using namespace std;

struct STNode {
    int start;
    int end;
    int sum;
    STNode * left;
    STNode * right;
    // struct也需要一個constructer
    STNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){
    }
};


class NumArray {
    STNode* root;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        root = build_tree(0, n-1, nums);
    }

    void print_root(){
        cout << "sum: " << root->sum << " / start: " << root->start << " / end: " << root->end << endl;
        cout << "right leaf sum: " << root->right->sum << endl;
    }
    
    void update(int i, int val) {
        update_val(i, val, root);
    }
    
    int sumRange(int i, int j) {
        return sum_range(i, j, root);
    }

    int update_val(int i, int val, STNode* root){
        // 排除違法值
        if (i < root->start || i > root->end) return 0;

        // 邊界值 start == end 到達leaf
        if (i == root->start and i == root->end){
            int diff = 0;
            diff = root->sum - val;
            // cout << "before update root->sum: " << root->sum << endl;
            root->sum = val;
            // cout << "after update root->sum: " << root->sum << endl;
            return diff;
        }

        // 往子樹尋找
        int mid = root->start + (root->end - root->start)/2;
        int diff = 0;
        if(i <= mid){
            diff = update_val(i, val, root->left);
        } else{
            diff = update_val(i, val, root->right);
        }

        root->sum = root->sum - diff;

        return diff;
    };


    int sum_range(int i, int j, STNode* root){
        // 檢查違法條件
        if (i > j || root == nullptr){
            return 0;
        }

        // cout << "root->sum: " << root->sum << endl;

        // 邊界條件, 要求的是全部的range 總合
        if (i == root->start && j == root->end){
            // cout << "1. root->sum: " << root->sum << endl;
            return root->sum;
        }

        // [BUG] 上面已經滿足，這裡寫會造成recursion 始終停在root node
        // 邊界條件，reach the leaf
        // if (i == j){
        //     cout << "2. root->sum: " << root->sum << endl;
        //     return root->sum;
        // }

        
        // 往子樹尋找
        int mid = root->start + (root->end - root->start)/2;
        // 需要判斷 要加左子樹還右子樹
        if (j <= mid){
            // cout << "left tree" << endl;
            return sum_range(i, j, root->left);
        } else if (i > mid){
            // cout << "right tree" << endl;
            return sum_range(i, j, root->right);
        }

        // cout << "both tree" << endl;
        return sum_range(i, mid, root->left) + sum_range(mid+1, j, root->right);
    }

    STNode* build_tree(int start, int end, vector<int> & nums){
        // 檢查違法條件
        if (start > end) {
            return nullptr;
        }

        // build_tree 需要初始化！
        STNode* root = new STNode(start, end);
        // cout << "start: " << start << " / end:" << end << endl;
        // print_root();
        // cout << "init root->sum: " << root->sum << endl;

        // 邊界條件，只有一個時，此時start不一定會是0 !!
        if (start == end){
            root->sum = nums[start]; // 有可能 start, end 都是 3
            // root->sum = nums[0];
            // cout << "leaf root->sum: " << root->sum << endl;
            return root;
        }

        // 注意mid算法
        int mid = start + (end -start)/2;
        // 情況一: 只要建左子樹
        // 情況二: 只要建右子樹
        // 在build_tree不需要分開處理
        // 情況三: 左右子樹都得建
        // nums 需要拆嗎？
        root->left = build_tree(start, mid, nums);
        root->right = build_tree(mid+1, end, nums);

        root->sum = root->left->sum + root->right->sum;
        return root;


    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main(){
    // vector<int> nums = {1,3,5};
    // NumArray numArray(nums);
    // // numArray.print_root();
    // cout << numArray.sumRange(0, 2) << endl;
    // numArray.print_root();
    // numArray.update(1, 2);
    // numArray.print_root();
    // cout <<  numArray.sumRange(0, 2) << endl;;

    vector<int> nums = {9, -8};
    NumArray numArray(nums);
    numArray.print_root();
    numArray.update(0, 3);
    numArray.print_root();
    cout << numArray.sumRange(1, 1) << endl;
    // cout << numArray.sumRange(0, 1) << endl;
    // numArray.update(1, -3);
    // cout << numArray.sumRange(0, 1) << endl;

    return 0;
}