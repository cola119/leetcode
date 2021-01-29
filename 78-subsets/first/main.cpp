#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans = {};
        backtrack(nums, 0, vector<int>(), ans);
        return ans;
    }

    void backtrack(vector<int> &nums, int k, vector<int> subset, vector<vector<int>> &ans)
    {
        if (k == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        backtrack(nums, k + 1, subset, ans);
        subset.push_back(nums[k]);
        backtrack(nums, k + 1, subset, ans);
    }
};

int main()
{
    Solution *solver = new Solution();

    vector<int> v1 = {1, 2, 3};
    vector<vector<int>> ans = solver->subsets(v1);
    for (auto array : ans)
    {
        std::cout << "["
                  << "";
        for (auto d : array)
        {
            std::cout << d << ",";
        }
        std::cout << "]"
                  << ", ";
    }

    std::cout << "" << std::endl;

    return 0;
}
