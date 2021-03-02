class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT32_MIN;
        vector<int> p(nums.size(), 0);
        p[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            p[i] = p[i - 1] + nums[i];
        }
        for (int len = 1; len <= nums.size(); len++)
        {
            for (int i = 0; i + len <= nums.size(); i++)
            {
                int val = p[i + len - 1] - (i == 0 ? 0 : p[i - 1]);
                res = max(res, val);
            }
        }
        return res;
    }
};