/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> ans;
        ans.push_back(root->val);
        helper(root->children, ans);
        return ans;
    }
    
    void helper(vector<Node*>& children, vector<int>& ans) {
        if(children.size() == 0) return;
        for(auto node : children) {
            ans.push_back(node->val);
            helper(node->children, ans);
        }
    }
};