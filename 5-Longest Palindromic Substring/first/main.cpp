#include <iostream>
#include <string>
#include <unordered_set>
#include <cmath>

// computation: O(n^3)

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans = "";
        int n = s.length();
        int start = 0;

        while (start < n - ans.length())
        {
            for (int last = start + ans.length(); last < n; last++)
            {
                bool is_palindromic = true;
                for (int i = start; i <= (start + floor((last - start) / 2)); i++)
                {
                    if (s[i] != s[last + start - i])
                    {
                        is_palindromic = false;
                        break;
                    }
                }
                if (is_palindromic)
                {
                    string sub = s.substr(start, last - start + 1);
                    if (sub.length() > ans.length())
                    {
                        ans = sub;
                    }
                }
                else
                {
                    is_palindromic = true;
                }
            }
            start++;
        }

        return ans;
    }
};

int main()
{

    Solution *solver = new Solution();

    assert(solver->longestPalindrome("babad") == "bab");
    assert(solver->longestPalindrome("cbbd") == "bb");
    assert(solver->longestPalindrome("a") == "a");
    assert(solver->longestPalindrome("ac") == "a");

    return 0;
}

// 7'41