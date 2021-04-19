class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stack;
        unordered_set<int> set;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c == '(') {
                stack.push(i);
            } else if(c == ')') {
                if(stack.empty()) {
                    set.insert(i);
                } else {
                    stack.pop();
                }
            }
        }
        while(!stack.empty()) {
            int idx = stack.top(); stack.pop();
            set.insert(idx);
        }
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            if(set.find(i) != set.end()) continue;
            ans += s[i];
        }
        return ans;
    }
};