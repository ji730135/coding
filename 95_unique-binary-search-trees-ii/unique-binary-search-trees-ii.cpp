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
    vector<TreeNode *> getTree(int begin, int end)
    {
        vector<TreeNode *> res;
        if (begin > end)
        {
            res.push_back(NULL);
            return res;
        }
        for (int i = begin; i < end + 1; i++)
        {
            vector<TreeNode *> leftNodes = getTree(begin, i - 1);
            vector<TreeNode *> rightNodes = getTree(i + 1, end);
            for (auto left : leftNodes)
            {
                for (auto right : rightNodes)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return vector<TreeNode *>();
        }
        return getTree(1, n);
    }
};