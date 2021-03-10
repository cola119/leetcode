class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        return helper(coins, amount, dp);
    }
    int helper(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount < 0)
            return -1;
        if (amount == 0)
            return 0;
        if (dp[amount] != 0)
            return dp[amount];
        int min = INT32_MAX;
        for (auto coin : coins)
        {
            int res = helper(coins, amount - coin, dp);
            if (res >= 0 && res < min)
            {
                min = 1 + res;
            }
        }
        dp[amount] = min == INT32_MAX ? -1 : min;
        return dp[amount];
    }
};