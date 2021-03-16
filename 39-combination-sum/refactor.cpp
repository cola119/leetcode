class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        helper(candidates, target, result, current, 0);
        return result;
    }

    void helper(vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &current, int from)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }
        for (int i = from; i < candidates.size(); i++)
        {
            int num = candidates[i];
            if (target - num < 0)
                continue;
            current.push_back(num);
            helper(candidates, target - num, result, current, i);
            current.pop_back();
        }
    }
};