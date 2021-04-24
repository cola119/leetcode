class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> memo = {triangle[0][0]};
        for(int row = 1; row < triangle.size(); row++) {
            vector<int> newMemo(triangle.size(), INT_MAX);
            for(int col = 0; col <= row; col++) {
                int small = INT_MAX;
                if(col > 0) small = memo[col-1];
                if(col < row) small = min(small, memo[col]);
                int val = triangle[row][col] + small;
                newMemo[col] = val;
            }
            memo = newMemo;
        }
        int small = INT_MAX;
        for(auto val : memo) {
            small = min(small, val);
        }
        return small;
    }
};