class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for(auto d : data) if(d == 1) ones++;
        int ans = 0;
        for(int i = 0; i < ones; i++) {
            if(data[i] == 0) ans++;
        }
        int cnt = ans;
        for(int i = 1; i+ones-1 < data.size(); i++) {
            if(data[i-1] == 1 && data[i+ones-1] == 0) cnt++;
            if(data[i-1] == 0 && data[i+ones-1] == 1) cnt--;
            ans = min(ans, cnt);
        }
        return ans;
    }
};