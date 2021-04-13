class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        if (n == 1)
            return {1};
        vector<int> ans;
        ans.push_back(1);
        int prev = 1;
        bool is_plus = true;
        for (int i = k; i > 0; i--)
        {
            if (is_plus)
            {
                ans.push_back(prev + i);
                prev += i;
            }
            else
            {
                ans.push_back(prev - i);
                prev -= i;
            }
            is_plus = !is_plus;
        }
        prev = k + 1;
        for (int i = ans.size(); i < n; i++)
        {
            ans.push_back(prev + 1);
            prev += 1;
        }
        return ans;
    }
};