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
    void inorderTraversal(TreeNode *root, vector<int> &sequence)
    {
        if (root != NULL)
        {
            inorderTraversal(root->left, sequence);
            sequence.push_back(root->val);
            inorderTraversal(root->right, sequence);
        }
    }

    bool isValidBST(TreeNode *root)
    {
        vector<int> seq;
        inorderTraversal(root, seq);
        for (int i = seq.size() - 1; i > 0; i--)
        {
            if (seq[i] <= seq[i - 1])
                return false;
        }
        return true;
    }
};
//以下是经典错法
// //若为空树，则为真；
// //若为非空树，则比较此根节点的左孩子是否小于根节点且右孩子大于根节点。若成立，则判断左右子树是不是BST。若是，则为BST；若不是，则不是BST。
// class Solution
// {
// public:
//     bool isValidBST(TreeNode *root)
//     {
//         if (root == nullptr)
//             return true;
//         if (root->left != nullptr)
//         {
//             if (root->left->val >= root->val)
//                 return false;
//         }
//         if (root->right != nullptr)
//         {
//             if (root->right->val <= root->val)
//                 return false;
//         }
//         if (!isValidBST(root->left) || !isValidBST(root->right))
//             return false;
//         return true;
//     }
// };