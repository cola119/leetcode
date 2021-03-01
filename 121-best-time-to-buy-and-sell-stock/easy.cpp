class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        int min = INT32_MAX;
        for (const auto price : prices)
        {
            if (price < min)
            {
                min = price;
            }
            else if (price - min > profit)
            {
                profit = price - min;
            }
        }

        return profit;
    }
};