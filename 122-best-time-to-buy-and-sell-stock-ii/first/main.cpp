#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};

int main()
{
    Solution *solver = new Solution();

    vector<int> v1 = {7, 1, 5, 3, 6, 4};
    assert(solver->maxProfit(v1) == 7);

    v1 = {1, 2, 3, 4, 5};
    assert(solver->maxProfit(v1) == 4);

    v1 = {7, 6, 4, 3, 1};
    assert(solver->maxProfit(v1) == 0);

    return 0;
}