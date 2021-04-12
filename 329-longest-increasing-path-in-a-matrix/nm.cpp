class Solution
{
    vector<vector<int>> dp;

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        dp.assign(nRow, vector<int>(nCol, 0));
        int ans = 0;
        for (int i = 0; i < nRow; i++)
        {
            for (int j = 0; j < nCol; j++)
            {
                if (dp[i][j] == 0)
                {
                    int m = find_max_len(i, j, matrix);
                    dp[i][j] = 1 + m;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }

    int find_max_len(int i, int j, vector<vector<int>> &matrix)
    {
        int r = helper(i, j, i, j + 1, matrix);
        int b = helper(i, j, i + 1, j, matrix);
        int l = helper(i, j, i, j - 1, matrix);
        int t = helper(i, j, i - 1, j, matrix);
        int m = max(r, max(b, max(l, t)));
        return m;
    }

    int helper(int p_row, int p_col, int row, int col, vector<vector<int>> &matrix)
    {
        int nRow = matrix.size();
        int nCol = matrix[0].size();
        if (row > nRow - 1 || row < 0 || col > nCol - 1 || col < 0)
            return 0;
        if (matrix[p_row][p_col] >= matrix[row][col])
            return 0;
        if (dp[row][col] > 0)
            return dp[row][col];
        int m = find_max_len(row, col, matrix);
        dp[row][col] = 1 + m;
        return 1 + m;
    }
};