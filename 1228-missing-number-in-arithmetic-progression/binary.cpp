class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int diff = (arr.back() - arr.front()) / n;
        int l = 0;
        int r = arr.size()-1;
        while(l < r) {
            int m = (l+r) / 2;
            if(arr[m] == arr[0] + m*diff) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return arr[0] + diff*l;
    }
};