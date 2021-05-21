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
class Solution {
public:
    // [3,9,20,null,null,15,7]
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while(!q.empty()) {
            int size = q.size(); // 2
            vector<int> levels;
            for(int i = 0; i < size; i++) {
                auto node = q.front(); q.pop(); // 20
                levels.push_back(node->val);
                if(node->left) q.push(node->left); // 
                if(node->right) q.push(node->right); // 
            }
            ans.push_back(levels); // {{3}, {9,20}}
        }
        return ans;
    }
};