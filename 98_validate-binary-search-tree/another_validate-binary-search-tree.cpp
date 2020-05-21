#include <stack>
#include <limits.h>
using namespace std;

//Definition for a binary tree node.
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
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> stack;
        long pre = LONG_MIN;
        while (!stack.empty() || root != NULL)
        {
            while (root != NULL)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (pre >= root->val)
                return false;
            pre = root->val;
            root = root->right;
        }
        return true;
    }
};
