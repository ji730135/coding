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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> List;
        if (root == NULL)
            return List;
        queue<TreeNode *> queue;
        bool flag = true;
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
            if (!flag)
            {
                int le_len = level.size();
                for (int k = 0; k < le_len / 2; k++)
                    swap(level[k], level[le_len - k - 1]);
                List.push_back(level);
                flag = !flag;
            }
            else
            {
                List.push_back(level);
                flag = !flag;
            }
            level.clear();
        }
        return List;
    }
};