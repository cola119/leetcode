class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // 10,11,1,2,3,4,5,6
        int min = nums[0];
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (min <= nums[mid])
                left = mid + 1;
            else
            {
                min = nums[mid];
                right = mid - 1;
            }
        }
        return min;
    }
};