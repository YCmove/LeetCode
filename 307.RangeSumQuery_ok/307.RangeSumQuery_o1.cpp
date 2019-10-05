// Very Detailed
// https://leetcode.com/problems/range-sum-query-mutable/discuss/75721/strongly-recommend-for-beginnersclean-C%2B%2B-implementation-with-detailed-explaination

#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
};

class NumArray {
    // 此 root 為絕對的root node
    SegmentTreeNode* root;

public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        root = buildTree(nums, 0, n-1);
    }

    void print_root(){
        cout << "sum: " << root->sum << " / start: " << root->start << " / end: " << root->end << endl;
    }
   
    void update(int i, int val) {
        modifyTree(i,val,root);
    }

    int sumRange(int i, int j) {
        return queryTree(i, j, root);
    }

    // buildTree method 會回傳 ptr to a root node
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end) {
        if(start > end) return nullptr;

        // 初始化 root node
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        // cout << "start: " << start << " / end:" << end << endl;
        // print_root();

        // 傳入nums array 只有一個時
        if(start == end) {
            // 更新root node的 sum
            root->sum = nums[start];
            return root;
        }

        // 傳入nums array > 一個時, 分成左子樹與右子樹
        int mid = start + (end - start) / 2; // 注意這個算法！！
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);

        // 更新root node的 sum
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int modifyTree(int i, int val, SegmentTreeNode* root) {
        if(root == nullptr) return 0;

        // 全樹只有一個node(root node), 代表已經recursive到了leaf
        int diff;
        if(root->start == i && root->end == i) {
            diff = val - root->sum;
            root->sum = val; // 更新sum
            return diff; // 回傳diff, 是為了更新所有子樹node的sum資訊
        }

        int mid = (root->start + root->end) / 2;
        if(i > mid) { // mid 以前(包含mid))左子樹
            diff = modifyTree(i, val, root->right);
        } else { // mid + 1(不包含mid)) 右子樹
            diff = modifyTree(i, val, root->left);
        }
        root->sum = root->sum + diff;
        return diff;
    }

    // sumRange
    int queryTree(int i, int j, SegmentTreeNode* root) {
        // root若為nullptr代表根本還沒有數字進來過
        if(root == nullptr) return 0;

        // 邊界條件, query的範圍是全部的tree
        if(root->start == i && root->end == j) return root->sum;

        // 代表需要繼續往子樹找
        int mid = (root->start + root->end) / 2;

        if(i > mid) return queryTree(i,j,root->right); // mid - left tree
        if(j <= mid) return queryTree(i,j,root->left); // mid+1 - right tree

        // i <= mid and j > mid, 代表i,j都分別還在左右子樹的範圍，需要左右都找
        return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);


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
    numArray.update(0, 3);
    cout << numArray.sumRange(1, 1) << endl;
    // cout << numArray.sumRange(0, 1) << endl;
    // numArray.update(1, -3);
    // cout << numArray.sumRange(0, 1) << endl;

    return 0;
}