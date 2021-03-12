class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        backtrack("", 0, 0, result, n);
        return result;
    }

    void backtrack(string current, int open, int close, vector<string> &result, int n)
    {
        if (current.length() == 2 * n)
        {
            result.push_back(current);
            return;
        }
        if (open < n)
        {
            backtrack(current + "(", open + 1, close, result, n);
        }
        if (close < open)
        {
            backtrack(current + ")", open, close + 1, result, n);
        }
    }
};