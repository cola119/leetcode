class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
            return 0;
        int ans = 0;
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                ans = max(ans, countIslandArea(grid, row, col));
            }
        }
        return ans;
    }

    int countIslandArea(vector<vector<int>> &grid, int row, int col)
    {
        if (grid[row][col] == 0)
            return 0;
        grid[row][col] = 0;
        int cnt = 1;
        if (row - 1 >= 0)
            cnt += countIslandArea(grid, row - 1, col);
        if (col - 1 >= 0)
            cnt += countIslandArea(grid, row, col - 1);
        if (row + 1 < grid.size())
            cnt += countIslandArea(grid, row + 1, col);
        if (col + 1 < grid[0].size())
            cnt += countIslandArea(grid, row, col + 1);
        return cnt;
    }
};