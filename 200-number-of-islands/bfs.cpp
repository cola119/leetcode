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
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        auto cell = q.front();
                        q.pop();
                        int _i = cell.first;
                        int _j = cell.second;
                        if (_i + 1 < n && grid[_i + 1][_j] == '1')
                        {
                            q.push({_i + 1, _j});
                            grid[_i + 1][_j] = '0';
                        }
                        if (_i - 1 >= 0 && grid[_i - 1][_j] == '1')
                        {
                            q.push({_i - 1, _j});
                            grid[_i - 1][_j] = '0';
                        }
                        if (_j + 1 < m && grid[_i][_j + 1] == '1')
                        {
                            q.push({_i, _j + 1});
                            grid[_i][_j + 1] = '0';
                        }
                        if (_j - 1 >= 0 && grid[_i][_j - 1] == '1')
                        {
                            q.push({_i, _j - 1});
                            grid[_i][_j - 1] = '0';
                        }
                    }
                }
            }
        }
        return cnt;
    }
};