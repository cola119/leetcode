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
    int pInt = 0;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;
        return helper(preorder, inorder, 0, inorder.size() - 1, map);
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int start, int end, unordered_map<int, int> &map)
    {
        if (start > end || pInt > preorder.size())
            return nullptr;
        TreeNode *node = new TreeNode(preorder[pInt]);
        int i = map[preorder[pInt++]];
        node->left = helper(preorder, inorder, start, i - 1, map);
        node->right = helper(preorder, inorder, i + 1, end, map);
        return node;
    }
};