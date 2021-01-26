#include <cassert>
#include <iostream>
using namespace std;

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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        targetSum -= root->val;
        if (isLeaf(root))
        {
            return (targetSum == 0);
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }

    bool isLeaf(TreeNode *node)
    {
        return node->right == nullptr && node->left == nullptr;
    }
};

int main()
{
    Solution *solver = new Solution();

    TreeNode *root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), new TreeNode()), new TreeNode(8, new TreeNode(13), new TreeNode(4, new TreeNode(), new TreeNode(1))));
    assert(solver->hasPathSum(root, 22) == true);

    root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    assert(solver->hasPathSum(root, 5) == false);

    root = new TreeNode();
    assert(solver->hasPathSum(root, 1) == false);

    root = new TreeNode(-2, new TreeNode(), new TreeNode(-3));
    assert(solver->hasPathSum(root, -5) == true);

    return 0;
}