class Solution
{
public:
    // [2,7,9,3,1]
    // memo
    // [2,7,11,11,12]
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> memo(nums.size(), 0);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            int taken = nums[i] + memo[i - 2];
            int notTaken = memo[i - 1];
            memo[i] = max(taken, notTaken);
        }
        return memo[nums.size() - 1];
    }
};