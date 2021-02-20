class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                }
                helper(grid, i, j);
            }
        }
        return cnt;
    }

    void helper(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return;
        }
        auto cell = grid[i][j];
        if (cell == '1')
        {
            grid[i][j] = '#';
            helper(grid, i - 1, j);
            helper(grid, i + 1, j);
            helper(grid, i, j + 1);
            helper(grid, i, j - 1);
        }
    }
};