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
        stack<Node*> s;
        s.push(root);
        while(!s.empty()) {
            Node* node = s.top(); s.pop();
            if(!node) continue;
            ans.push_back(node->val);
            reverse(node->children.begin(), node->children.end());
            for(auto c: node->children) s.push(c);
        }
        return ans;
    }
};