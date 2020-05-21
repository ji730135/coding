#include <math.h>
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
    int helper(TreeNode *root, int depth)
    {
        if (!root)
            return depth;
        if (!root->left && !root->right)
            return depth + 1;
        return max(helper(root->left, depth + 1), helper(root->right, depth + 1));
    }
    int maxDepth(TreeNode *root)
    {
        return helper(root, 0);
    }
};