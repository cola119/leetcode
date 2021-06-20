class Solution {
public:
    /*
    [[1,4],[0,2,3]]
    q: [2,1] color=1, i=2
    */
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> memo(3, vector<int>());
        for(int i = 0; i < colors.size(); i++) {
            memo[colors[i]-1].push_back(i);
        }
        vector<int> ans;
        for(auto q: queries) {
            int index = q[0];
            int color = q[1]-1;
            if(memo[color].size() == 0) {
                ans.push_back(-1);
            } else if(memo[color].size() == 1) {
                ans.push_back(abs(memo[color][0]-index));
            } else {
                int memoIndex = binarySearch(memo[color], index);
                int m = memo[color][memoIndex];
                if(memoIndex == 0) { 
                    int r = memo[color][memoIndex+1];
                    ans.push_back(min(abs(m-index), abs(r-index)));
                } else if(memoIndex == memo[color].size()-1) {
                    int l = memo[color][memoIndex-1];
                    ans.push_back(min(abs(m-index), abs(l-index)));
                } else {
                    int l = memo[color][memoIndex-1];
                    int r = memo[color][memoIndex+1];
                    int a = min(abs(l-index), min(abs(m-index), abs(r-index)));
                    ans.push_back(a);
                }
            }
        }
        return ans;
    }
    
    int binarySearch(vector<int>& vec, int target) {
        int n = vec.size();
        int left = 0;
        int right = n-1;
        while(left < right) {
            int m = (left+right)/2;
            if(vec[m] == target) return m;
            else if(target < vec[m]) right = m;
            else left = m+1;
        }
        return left;
    }
    
    int abs(int a) {
        return a > 0 ? a : -a;
    }
};