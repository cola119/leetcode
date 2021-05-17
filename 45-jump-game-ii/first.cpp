class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0;
        int cnt = 0;
        int n = nums.size();
        if(n == 1) return 0;
        while(pos < n) {
            int dist = nums[pos];
            if(dist == 0) {
                pos++;
                cnt++;
                continue;
            }
            int opt_dist = 0;
            int max_dist = 0;
            while(dist > 0) {
                if(pos+dist >= n-1) {
                    return cnt+1;
                }
                int candidate = nums[pos+dist];
                int jumped_dist = pos+dist+candidate;
                if(max_dist <= jumped_dist) {
                    opt_dist = dist;
                    max_dist = jumped_dist;
                }
                dist--;
            }
            cnt++;
            pos += opt_dist;
        }
        return cnt;
    }
};