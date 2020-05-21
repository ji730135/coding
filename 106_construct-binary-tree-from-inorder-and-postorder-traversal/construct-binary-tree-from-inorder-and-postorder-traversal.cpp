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
    TreeNode *generate(vector<int> &inorder, int i_left, int i_right, vector<int> &postorder, int p_left, int p_right)
    {
        if (p_left > p_right)
            return NULL;
        TreeNode *root = new TreeNode(postorder[p_right]);
        int inK = i_left;
        for (; inK <= i_right; inK++)
        {
            if (inorder[inK] == root->val)
                break;
        }
        root->left = generate(inorder, i_left, inK - 1, postorder, p_left, p_left + inK - i_left - 1);
        root->right = generate(inorder, inK + 1, i_right, postorder, p_left + inK - i_left, p_right - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty())
            return NULL;
        return generate(inorder, 0, inorder.size() - 1, postorder, 0, inorder.size() - 1);
    }
};