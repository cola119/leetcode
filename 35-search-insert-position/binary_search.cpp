class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int m = (left + right) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                left = m + 1;
            if (target < nums[m])
                right = m - 1;
        }
        return left;
    }
};