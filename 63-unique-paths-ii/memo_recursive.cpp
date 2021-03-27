class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(obstacleGrid, 0, 0, dp);
    }

    int helper(vector<vector<int>> &obstacleGrid, int x, int y, vector<vector<int>> &dp)
    {
        if (obstacleGrid[x][y] == 1)
        {
            dp[x][y] = 0;
            return 0;
        }
        if (dp[x][y] > -1)
            return dp[x][y];

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (x == m - 1 && y == n - 1)
            return 1;
        int res = 0;
        if (x + 1 < m && obstacleGrid[x + 1][y] == 0)
        {
            res +=　helper(obstacleGrid, x + 1, y, dp);
        }
        if (y + 1 < n && obstacleGrid[x][y + 1] == 0)
        {
            res += helper(obstacleGrid, x, y + 1, dp);
        }
        dp[x][y] = res;
        return res;
    }
};