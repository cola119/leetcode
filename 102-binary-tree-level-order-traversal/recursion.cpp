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
    vector<vector<int>> ans;

public:
    void helper(TreeNode *node, int depth)
    {
        if (ans.size() == depth)
        {
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(node->val);
        if (node->left)
        {
            helper(node->left, depth + 1);
        }
        if (node->right)
        {
            helper(node->right, depth + 1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        helper(root, 0);
        return ans;
    }
};