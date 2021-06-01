class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            int diff = nums[i+1] - nums[i];
            res = max(res, diff);
        }
        return res;
    }
};