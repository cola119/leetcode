/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return nullptr;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res = nullptr;
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node->val > p->val)
            {
                res = min(res, node);
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        return res;
    }

    TreeNode *min(TreeNode *a, TreeNode *b)
    {
        if (!a)
            return b;
        if (!b)
            return a;
        return a->val > b->val ? b : a;
    }
};