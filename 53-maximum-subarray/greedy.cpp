class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int allMax = nums[0];
        int partialMax = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            partialMax = max(partialMax + nums[i], nums[i]);
            allMax = max(allMax, partialMax);
        }
        return allMax;
    }
};