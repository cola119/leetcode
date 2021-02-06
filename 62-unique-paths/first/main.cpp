class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> P(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    P[i][j] = 1;
                else
                {
                    int top = i >= 1 ? P[i - 1][j] : 0;
                    int left = j >= 1 ? P[i][j - 1] : 0;
                    P[i][j] = top + left;
                }
            }
        }
        return P[m - 1][n - 1];
    }
};