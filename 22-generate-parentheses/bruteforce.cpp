class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        vector<int> current(2 * n, 0);
        helper(0, current, result);
        return result;
    }

    void helper(int pos, vector<int> &current, vector<string> &result)
    {
        if (pos == current.size())
        {
            string res = "";
            int sum = 0;
            for (auto num : current)
            {
                sum += num;
                if (sum < 0)
                    return;
                res += num == 1 ? "(" : ")";
            }
            if (sum == 0)
            {
                result.push_back(res);
            }
        }
        else
        {
            current[pos] = 1;
            helper(pos + 1, current, result);
            current[pos] = -1;
            helper(pos + 1, current, result);
        }
    }
};