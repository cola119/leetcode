class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    int helper(vector<int> &nums, int left, int right)
    {
        int n = right - left;
        if (n == 0)
            return nums[left];
        int c = (right + left) / 2;
        int leftSum = helper(nums, left, c);
        int rightSum = helper(nums, c + 1, right);
        int cross = crossSum(nums, left, right, c);
        return max(max(leftSum, rightSum), cross);
    }

    int crossSum(vector<int> &nums, int left, int right, int center)
    {
        int leftSum = INT32_MIN;
        int current = 0;
        for (int i = center; i > left - 1; i--)
        {
            current += nums[i];
            leftSum = max(current, leftSum);
        }
        int rightSum = 0;
        current = 0;
        for (int i = center + 1; i < right + 1; i++)
        {
            current += nums[i];
            rightSum = max(current, rightSum);
        }
        return rightSum + leftSum;
    }
};