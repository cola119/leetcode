#include <iostream>
#include <string>
#include <unordered_map>

// comp: O(n)
// space(hashmap): O(min(m,n))
class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int lengthOfLongestSubstring(std::string s)
    {

        std::unordered_map<char, int> hash;
        int ans = 0;
        int n = s.size();

        for (int i = 0, j = 0; j < n; j++)
        {
            if (hash.find(s[j]) != hash.end())
            {
                // a bit more efficent compared to the second answer;
                i = max(i, hash.find(s[j])->second + 1);
                hash[s[j]] = j;
            }
            else
            {
                hash.insert({s[j], j});
            }
            ans = max(ans, j - i + 1);
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
    assert(solver->lengthOfLongestSubstring("abba") == 2);
    assert(solver->lengthOfLongestSubstring("aaaaa") == 1);
    assert(solver->lengthOfLongestSubstring("abv") == 3);
    assert(solver->lengthOfLongestSubstring("dvdf") == 3);
    assert(solver->lengthOfLongestSubstring("abcabcbb") == 3);
    assert(solver->lengthOfLongestSubstring("anviaj") == 5);

    return 0;
}