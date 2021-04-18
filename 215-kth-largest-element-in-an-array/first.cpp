class Solution {
public:
    /*
        [3,2,1,5,6,4], k=2
        priority_queue q;
        N=size(nums);
        →
        [3]
        [2,3]
        [1,2,3]
        [1,2,3,5]
        [1,2,3,5,6]
        [1,2,3,4,5,6]
        [1,2,3,4,5]
        O(NlogM)

        sort
        O(NlogN)
    */
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(auto num : nums) {
            q.push(num);
        }
        
        for(int i = 0; i < k-1; i++) {
            q.pop();
        }
        return q.top();
    }
};