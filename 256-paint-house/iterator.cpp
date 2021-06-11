class Solution {
public:
    /*
    [[17,2,17],[16,16,5],[14,3,19]]
    min_costs[0][0] = 17 min_costs[0][1] = 2 min_costs[0][2] = 17
    min_costs[1][0] = 18 min_costs[1][1] = 33 min_costs[1][2] = 7
    min_costs[2][0] = 21 min_costs[2][1] = 10 min_costs[2][2] = 37
    
    j=0,1,2
    P(i,j) = costs[i][j]+min(P(i-1,k)) k=0,1,2 ∧ k!=i IF i > 0
    P(i,j) = costs[i][j] IF i == 0
    */
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int a = costs[0][0];
        int b = costs[0][1];
        int c = costs[0][2];
        for(int i = 1; i < n; i++) {
            int _a = costs[i][0] + min(b, c);
            int _b = costs[i][1] + min(a, c);
            int _c = costs[i][2] + min(a, b);
            a = _a;
            b = _b;
            c = _c;
        }
        return min(a, min(b, c));
    }
};