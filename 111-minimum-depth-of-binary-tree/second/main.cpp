#include <cassert>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(0), left(left), right(right) {}
};

class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;

        int depth = INT32_MAX;
        if (root->left)
            depth = min(minDepth(root->left), depth);
        if (root->right)
            depth = min(minDepth(root->right), depth);

        return depth + 1;
    }

    int min(int a, int b)
    {
        return a > b ? b : a;
    }
};

int main()
{
    Solution *solver = new Solution();

    return 0;
}