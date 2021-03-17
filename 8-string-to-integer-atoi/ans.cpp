class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.length() == 0)
            return 0;
        int i = 0;
        int sign = 1;
        int result = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
            sign = (s[i++] == '-') ? -1 : 1;

        while (i < s.length() && s[i] >= '0' && s[i] <= '9')
        {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (s[i++] - '0');
        }

        return result * sign;
    }
};