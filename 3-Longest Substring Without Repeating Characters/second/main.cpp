#include <iostream>
#include <string>
#include <unordered_set>

class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int lengthOfLongestSubstring(std::string s)
    {

        std::unordered_set<char> set;
        int i, j, ans;
        int n = s.size();
        i = j = ans = 0;

        while (i < n && j < n)
        {
            if (set.find(s[j]) != set.end())
            {
                set.erase(s[i]);
                i++;
            }
            else
            {
                set.insert(s[j]);
                j++;
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution *solver = new Solution();

    assert(solver->lengthOfLongestSubstring("") == 0);
    assert(solver->lengthOfLongestSubstring("a") == 1);
    assert(solver->lengthOfLongestSubstring("av") == 2);
    assert(solver->lengthOfLongestSubstring("aa") == 1);
    assert(solver->lengthOfLongestSubstring("aaaaa") == 1);
    assert(solver->lengthOfLongestSubstring("abv") == 3);
    assert(solver->lengthOfLongestSubstring("dvdf") == 3);
    assert(solver->lengthOfLongestSubstring("abcabcbb") == 3);
    assert(solver->lengthOfLongestSubstring("anviaj") == 5);

    return 0;
}