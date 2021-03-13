class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.length() == 0)
            return true;
        int pos = 0;
        for (auto str : t)
        {
            if (pos == s.length())
            {
                break;
            }
            if (str == s[pos])
            {
                pos++;
            }
        }
        return pos == s.length() ? true : false;
    }
};