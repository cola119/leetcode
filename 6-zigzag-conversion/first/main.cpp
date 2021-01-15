#include <string>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (s.length() == 1)
            return s;
        if (numRows == 1)
        {
            return s;
        }
        string ans = "";
        int n = s.length();
        int numColumns = floor(n / (2 * (numRows - 1))) + 1;
        for (int k = 0; k < numRows; k++)
        {
            if (k == 0)
            {
                for (int i = 0; i < numColumns; i++)
                {
                    int idx = i * 2 * (numRows - 1);
                    if (idx < n)
                        ans += s[idx];
                }
            }
            else if (k == numRows - 1)
            {
                for (int i = 0; i < numColumns; i++)
                {
                    int idx = (2 * i + 1) * (numRows - 1);
                    if (idx < n)
                    {
                        ans += s[idx];
                    }
                }
            }
            else
            {
                for (int i = 0; i <= numColumns; i++)
                {
                    int columnTopIdx = i * 2 * (numRows - 1);
                    if (columnTopIdx - k > 0 && columnTopIdx - k < n)
                    {
                        ans += s[columnTopIdx - k];
                    }
                    if (columnTopIdx + k > 0 && columnTopIdx + k < n)
                    {
                        ans += s[columnTopIdx + k];
                    }
                }
            }
        }

        // std::cout << ans << std::endl;
        return ans;
    }
};

int main()
{
    Solution *solver = new Solution();

    assert(solver->convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    assert(solver->convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    assert(solver->convert("ABCDE", 4) == "ABCED");

    return 0;
}