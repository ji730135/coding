//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return judge(root->left, root->right);
    }
    bool judge(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (left && right)
        {
            if (left->val != right->val)
                return false;
            return judge(left->right, right->left) && judge(left->left, right->right);
        }
        else
            return false;
    }
};