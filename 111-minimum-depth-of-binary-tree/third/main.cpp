#include <cassert>
#include <stack>

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
        int depth = INT32_MAX;
        stack<pair<TreeNode *, int>> s;
        s.push({root, 0});

        while (!s.empty())
        {
            auto pair = s.top();
            s.pop();
            TreeNode *node = pair.first;
            int _depth = pair.second;
            if (node->left == nullptr && node->right == nullptr)
            {
                depth = min(depth, _depth);
            }
            if (node->left)
                s.push({node->left, _depth + 1});
            if (node->right)
                s.push({node->right, _depth + 1});
        }

        return depth;
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