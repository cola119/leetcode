class Solution
{
    vector<vector<int>> memo;

public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        memo.assign(n + 1, vector<int>(n, -1));
        return helper(nums, -1, 0);
    }

    int helper(vector<int> &nums, int prev, int pos)
    {
        if (pos >= nums.size())
            return 0;
        if (memo[prev + 1][pos] >= 0)
            return memo[prev + 1][pos];
        int notTaken = helper(nums, prev, pos + 1);
        int taken = -1;
        if (prev < 0 || nums[pos] > nums[prev])
        {
            taken = 1 + helper(nums, pos, pos + 1);
        }
        memo[prev + 1][pos] = max(notTaken, taken);
        return memo[prev + 1][pos];
    }
};