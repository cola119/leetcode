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
        queue<pair<TreeNode *, int>> q;
        if (root != nullptr)
            q.push({root, 1});
        while (!q.empty())
        {
            auto pair = q.front();
            auto node = pair.first;
            auto depth = pair.second;
            q.pop();
            if (node->right == nullptr && node->left == nullptr)
                return depth;
            if (node->right)
                q.push({node->right, depth + 1});
            if (node->left)
                q.push({node->left, depth + 1});
        }

        return 0;
    }
};

int main()
{
    Solution *solver = new Solution();

    return 0;
}