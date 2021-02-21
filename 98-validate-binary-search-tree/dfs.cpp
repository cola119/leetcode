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
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isValidNode(root, nullptr, nullptr);
    }

    bool isValidNode(TreeNode *node, TreeNode *minNode, TreeNode *maxNode)
    {
        if (node == nullptr)
            return true;
        if (
            (minNode != nullptr && node->val <= minNode->val) ||
            (maxNode != nullptr && node->val >= maxNode->val))
        {
            return false;
        }
        bool left_res = isValidNode(node->left, minNode, node);
        bool right_res = isValidNode(node->right, node, maxNode);
        return left_res && right_res;
    }
};