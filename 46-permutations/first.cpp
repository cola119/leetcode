/**
[[1]] // 1
[[1,2],[2,1]] // 1,2
[[1,2,3],[1,3,2],[3,1,2],[2,1,3],[2,3,1],[3,2,1]] // 1,2,3
**/

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 1)
            return {{nums[0]}};
        vector<vector<int>> result;
        auto last = nums[nums.size() - 1];
        auto first = vector<int>(nums.begin(), nums.end() - 1);
        auto prev = permute(first);
        for (auto array : prev)
        {
            for (int i = 0; i <= array.size(); i++)
            {
                vector<int> cur(array.size());
                copy(array.begin(), array.end(), cur.begin());
                cur.insert(cur.begin() + i, last);
                result.push_back(cur);
            }
        }
        return result;
    }
};