class Solution {
public:
    // 4, [1,2,3]
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> memo(target+1, -1);
        memo[0] = 1;
        // memo: [1, -1, -1, -1, -1], target: 4
        return helper(nums, target, memo);
    }
    int helper(vector<int>& nums, int target, vector<int>& memo) {
        if(target < 0) return 0;
        if(memo[target] >= 0) return memo[target];
        int cnt = 0;
        for(auto num: nums) {
            cnt += helper(nums, target - num, memo);
        }
        memo[target] = cnt;
        return cnt;
    }
};