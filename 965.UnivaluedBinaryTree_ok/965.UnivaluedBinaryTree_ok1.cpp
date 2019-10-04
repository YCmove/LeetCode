#include <iostream>
#include <algorithm> // std::find_if, min
#include <sstream>   // std::streamstring
#include <queue>     // std::queue

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool correct(TreeNode * node, int x)
    {
        if (node==NULL)
        {
            return true;
            // 空node代表這個樹枝到底了，代表上一個node是最底層
        }
        if (node->val != x)
        {
            return false;
        } else {
            return (correct(node->left, x) && correct(node->right, x));
        }
        }

    bool isUnivalTree(TreeNode *root)
    {
        const int value = root->val;
        return (correct(root->left, value) && correct(root->right, value));
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line = "[1,1,1,1,1,null,1]";
    // string line = "[2,2,2,7,6,4,2]";
    // while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);

    bool ret = Solution().isUnivalTree(root);

    string out = boolToString(ret);
    cout << out << endl;
    // }
    return 0;
}
