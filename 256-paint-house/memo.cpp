class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> memo(costs.size(), vector<int>(3, -1));
        return min(paint(memo, costs, 0, 0), min(paint(memo, costs, 0, 1), paint(memo, costs, 0, 2)));
    }
    
    int paint(vector<vector<int>>& memo, vector<vector<int>>& costs, int i, int color) {
        if(memo[i][color] >= 0) {
            return memo[i][color];
        }
        int cost = costs[i][color];
        if(i == costs.size() -1) {}
        else if(color == 0) {
            cost += min(paint(memo, costs, i+1, 1), paint(memo, costs, i+1, 2));
        } else if(color == 1) {
            cost += min(paint(memo, costs, i+1, 0), paint(memo, costs, i+1, 2));
        } else if(color == 2) {
            cost += min(paint(memo, costs, i+1, 0), paint(memo, costs, i+1, 1));
        }
        memo[i][color] = cost;
        return cost;
    }
};