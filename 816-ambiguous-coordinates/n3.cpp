class Solution {
public:
    /*
    1234
    (1,234)(12,34)(123,4)
    (1,2.34)(1,23.4)
    (1.2,34)(12,3.4)(1.2,3.4)
    0 0011
    
    */
    vector<string> ambiguousCoordinates(string s) {
        vector<string> ans;
        s = s.substr(1);
        s = s.substr(0, s.length()-1);
        int n = s.length();
        for(int i = 1; i < n; i++) {
            // separate left and right with comma
            string left = s.substr(0, i);
            string right = s.substr(i);
            // get results from insertDot
            vector<string> lefts = insertDot(left);
            if(lefts.size() == 0) continue;
            vector<string> rights = insertDot(right);
            if(rights.size() == 0) continue;
            // combine above results
            makeCoord(lefts, rights, ans);
        }
        return ans;
    }
    
    // 123 -> 123, 1.23, 12.3
    // 000 -> 
    // 000123 -> 0.00123
    // 123000 -> 123000
    // 0012300 -> 
    vector<string> insertDot(string s) {
        int n = s.length();
        if(n == 0) return {};
        if(n == 1) return {s};
        if(s[0] == '0') {
            if(s[n-1] == '0') return {};
            string str = "0." + s.substr(1);
            return {str};
        }
        if(s[n-1] == '0') {
            return {s};    
        }
        vector<string> res;
        res.push_back(s);
        for(int i = 1; i < n; i++) {
            string str = s.substr(0,i) + "." + s.substr(i);
            res.push_back(str);
        }
        return res;
    }
    
    void makeCoord(vector<string>& a, vector<string>& b, vector<string>& ans) {
        for(auto _a: a) {
            for(auto _b: b) {
                string coord = "(" + _a + ", " + _b + ")";
                ans.push_back(coord);
            }
        }
    }
};