class Solution {
public:
    // [15,13,12]
    // x-15 = 13-x , 2x = a[0]+a[1]
    // x-13 = 12-x , 2x = a[1]+a[2]
    // diff: -2,-1
    // [5,7,11,13]
    // diff: 2,4,2
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int diff1 = arr[1] - arr[0];
        int diff2 = arr[2] - arr[1];
        if(n == 3) {
            if((arr[0]+arr[1])%2 == 0) return (arr[0]+arr[1])/2;
            else return (arr[1]+arr[2])/2;
        }
        int diff3 = arr[3] - arr[2];
        int diff;
        if(diff1 == diff2 && diff2 == diff3) diff = diff1;
        else if(diff1 != diff2 && diff2 == diff3) diff = diff2;
        else diff = diff1;
        for(int i = 1; i < n; i++) {
            if(arr[i] - arr[i-1] != diff) {
                return (arr[i] + arr[i-1]) / 2;
            }
        }
        return 0;
    }
};