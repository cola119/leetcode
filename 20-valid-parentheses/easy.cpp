class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> logs;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                logs.push(c);
            }
            if (c == ')' || c == '}' || c == ']')
            {
                if (logs.empty())
                    return false;
                auto prev = logs.top();
                logs.pop();
                if (
                    !((c == ')' && prev == '(') || (c == '}' && prev == '{') || (c == ']' && prev == '[')))
                    return false;
            }
        }
        return logs.empty() ? true : false;
    }
};