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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
        {
            if (!p && !q)
                return true;
            else
                return false;
        }
        else if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
            return p->val == q->val;
        else
            return false;
    }
};