class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        return _lengthOfLIS(nums, INT32_MIN, 0);
    }

    int _lengthOfLIS(vector<int> &nums, int prev, int pos)
    {
        if (pos == nums.size())
            return 0;
        int taken = 0;
        if (prev < nums[pos])
        {
            taken = 1 + _lengthOfLIS(nums, nums[pos], pos + 1);
        }
        int not_taken = _lengthOfLIS(nums, prev, pos + 1);
        return cmax(taken, not_taken);
    }

    int cmax(int a, int b)
    {
        return a > b ? a : b;
    }
};