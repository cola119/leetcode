#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int lengthOfLongestSubstring(std::string s)
    {
        if (s.size() == 0)
            return 0;

        int start = 0;
        int cnt = 0;
        bool finished = false;
        std::unordered_map<char, bool> hash;

        while (!finished)
        {
            for (int i = start; i < s.size(); i++)
            {
                hash.insert({s[i], true});

                if (i + 1 > s.size() - 1)
                {
                    cnt = max(cnt, i - start + 1);
                    finished = true;
                }
                if (hash.find(s[i + 1]) != hash.end())
                {
                    cnt = max(cnt, i - start + 1);
                    start += 1;
                    hash.clear();
                    break;
                }
            }
        }

        return cnt;
    }
};

int main()
{
    Solution *solver = new Solution();

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