class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        int maxans = 1;
        for (int i = 1; i < n; i++)
        {
            int maxval = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    maxval = max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            maxans = max(maxans, dp[i]);
        }
        return maxans;
    }
};