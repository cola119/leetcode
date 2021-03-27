class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        return helper(obstacleGrid, 0, 0);
    }

    int helper(vector<vector<int>> &obstacleGrid, int x, int y)
    {
        if (obstacleGrid[x][y] == 1)
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (x == m - 1 && y == n - 1)
            return 1;
        int res = 0;
        if (x + 1 < m && obstacleGrid[x + 1][y] == 0)
        {
            res +=　helper(obstacleGrid, x + 1, y);
        }
        if (y + 1 < n && obstacleGrid[x][y + 1] == 0)
        {
            res += helper(obstacleGrid, x, y + 1);
        }
        return res;
    }
};