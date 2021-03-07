class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int D)
    {
        int left = 0;
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left <= right)
        {
            int m = (left + right) / 2;
            if (isAbleToShip(weights, D, m))
            {
                right = m - 1;
            }
            else
            {
                left = m + 1;
            }
        }
        return left;
    }

    bool isAbleToShip(vector<int> &weights, int D, int capacity)
    {
        int cap = capacity;
        int cnt = 1;
        int i = 0;
        while (i < weights.size())
        {
            if (cap - weights[i] < 0)
            {
                if (cnt == D)
                    return false;
                cap = capacity;
                cnt++;
            }
            else
            {
                cap -= weights[i];
                i++;
            }
        }
        return true;
    }
};