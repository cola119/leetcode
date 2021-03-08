class Solution
{
public:
    // [2,3,1,2,4,3]
    //        l   r
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int l = -1;
        int r = -1;
        int res = INT32_MAX;
        int sum = 0;
        while (l < n && r < n && l <= r)
        {
            if (sum >= target)
            {
                res = min(res, r - l);
            }
            if (sum <= target)
            {
                r++;
                if (r < n)
                    sum += nums[r];
            }
            else
            {
                l++;
                if (l < n)
                    sum -= nums[l];
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};