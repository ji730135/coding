#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> List;
        if (root == NULL)
            return List;
        queue<TreeNode *> queue;
        vector<int> level;
        queue.push(root);
        while (!queue.empty())
        {
            int length = queue.size();
            for (int i = 0; i < length; i++)
            {
                TreeNode *p = queue.front();
                queue.pop();
                level.push_back(p->val);
                if (p->left != NULL)
                    queue.push(p->left);
                if (p->right != NULL)
                    queue.push(p->right);
            }
            List.push_back(level);
            level.clear();
        }
        int le_len = List.size();
        for (int k = 0; k < le_len / 2; k++)
            swap(List[k], List[le_len - k - 1]);
        return List;
    }
};