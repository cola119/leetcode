#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        bool P[n][n];
        int length = 0;
        int start_idx = 0;

        for (int i = 0; i < n; i++)
        {
            P[i][i] = true;
            length = 1;
            start_idx = 0;
        }

        for (int i = 0; i + 1 < n; i++)
        {
            if (s[i] == s[i + 1])
            {
                P[i][i + 1] = true;
                start_idx = i;
                length = 2;
            }
        }

        for (int k = 3; k <= n; k++)
        {
            for (int l = 0; l < n - k + 1; l++)
            {
                int r = k + l - 1;
                if (P[l + 1][r - 1] && s[l] == s[r])
                {
                    P[l][r] = true;
                    if (k > length)
                    {
                        start_idx = l;
                        length = k;
                    }
                }
            }
        }

        std::cout << s.substr(start_idx, length) << std::endl;
        return s.substr(start_idx, length);
    }
};

int main()
{

    Solution *solver = new Solution();

    assert(solver->longestPalindrome("babad") == "bab");
    assert(solver->longestPalindrome("cbbd") == "bb");
    assert(solver->longestPalindrome("a") == "a");
    assert(solver->longestPalindrome("ac") == "a");
    assert(solver->longestPalindrome("aacabdkacaa") == "aacabdkacaa");

    return 0;
}