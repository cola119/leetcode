class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<vector<int>> current;
        helper(candidates, target, result, current, 0);
        return result;
    }

    // candidates = [2,3,6,7], target = 7
    // cur=[[2]], t=5
    // cur=[[2,2],[2,3]]
    void helper(vector<int> &candidates, int target, vector<vector<int>> &result, vector<vector<int>> &current, int from)
    {
        if (target == 0)
        {
            for (auto d : current)
                result.push_back(d);
            return;
        }
        for (int i = from; i < candidates.size(); i++)
        {
            int num = candidates[i];
            if (target - num < 0)
                continue;
            vector<vector<int>> newCurrent;
            if (current.size() == 0)
            {
                vector<int> newVec;
                newVec.push_back(num);
                newCurrent.push_back(newVec);
            }
            else
            {
                for (auto vec : current)
                {
                    vector<int> newVec(vec.size());
                    copy(vec.begin(), vec.end(), newVec.begin());
                    newVec.push_back(num);
                    newCurrent.push_back(newVec);
                }
            }
            helper(candidates, target - num, result, newCurrent, i);
        }
    }
};