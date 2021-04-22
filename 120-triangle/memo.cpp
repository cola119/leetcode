class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo(triangle.size(), vector<int>());
        for(int i = 0; i < triangle.size(); i++) {
            memo[i].resize(triangle[i].size(), INT_MIN);
        }
        return helper(triangle, 0, 0, memo);
    }
    // [[-1],[2,3],[1,-1,-3]]
    int helper(vector<vector<int>>& triangle, int row, int pos, vector<vector<int>>& memo) {
        if(row >= triangle.size()) return 0;
        if(memo[row][pos] != INT_MIN) return memo[row][pos];
        int left = triangle[row][pos] + helper(triangle, row+1, pos, memo);
        if(pos+1 >= triangle[row].size()) return left;
        int right = triangle[row][pos+1] + helper(triangle, row+1, pos+1, memo);
        
        int res = min(left, right);
        memo[row][pos] = res;
        return res;
    }
};