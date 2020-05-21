#include <vector>
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
    TreeNode *generate(vector<int> &preorder, int p_left, int p_right,
                       vector<int> &inorder, int i_left, int i_right)
    {
        if (p_left > p_right)
            return NULL;
        TreeNode *root = new TreeNode(preorder[p_left]);
        int inK = i_left;
        for (; inK <= i_right; inK++)
        {
            if (inorder[inK] == root->val)
                break;
        }
        root->left = generate(preorder, p_left + 1, p_left + inK - i_left, inorder, i_left, inK - 1);
        root->right = generate(preorder, p_left + inK - i_left + 1, p_right, inorder, inK + 1, i_right);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
            return NULL;
        return generate(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};