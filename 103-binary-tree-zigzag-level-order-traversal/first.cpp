/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        deque<pair<TreeNode *, int>> q;
        vector<vector<int>> ans;
        bool lr = true;
        q.push_back({root, 0});
        int prev_level = 0;
        ans.push_back(vector<int>());
        while (!q.empty())
        {
            auto p = lr ? q.front() : q.back();
            if (p.second != prev_level)
            {
                prev_level = p.second;
                ans.push_back(vector<int>());
                lr = !lr;
                continue;
            }
            auto node = p.first;
            auto level = p.second;
            ans[level].push_back(node->val);
            if (lr)
            {
                q.pop_front();
                if (node->left)
                    q.push_back({node->left, level + 1});
                if (node->right)
                    q.push_back({node->right, level + 1});
            }
            else
            {
                q.pop_back();
                if (node->right)
                    q.push_front({node->right, level + 1});
                if (node->left)
                    q.push_front({node->left, level + 1});
            }
        }
        return ans;
    }
};