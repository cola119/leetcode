class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
           return a[1] > b[1]; 
        });
        int res = 0;
        for(auto box: boxTypes) {
            if(truckSize - box[0] >= 0) {
                truckSize -= box[0];
                res += box[0] * box[1];
            } else {
                res += truckSize * box[1];
                break;
            }
        }
        return res;
    }
};