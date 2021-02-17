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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        stack<pair<TreeNode *, int>> s;
        s.push({root, 0});
        vector<vector<int>> ans;

        int max_depth = 0;

        while (!s.empty())
        {
            auto pair = s.top();
            s.pop();
            auto node = pair.first;
            auto depth = pair.second;

            max_depth = max(max_depth, depth);
            ans.resize(max_depth + 1);
            ans[depth].resize(ans[depth].size());
            ans[depth].push_back(node->val);

            if (node->right)
            {
                s.push({node->right, depth + 1});
            }
            if (node->left)
            {
                s.push({node->left, depth + 1});
            }
        }

        return ans;
    }
};