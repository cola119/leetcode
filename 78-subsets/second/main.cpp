#include <vector>
#include <iostream>

using namespace std;

void print_vec(vector<int> &v)
{
    std::cout << "["
              << "";
    for (auto d : v)
    {
        std::cout << d << ",";
    }
    std::cout << "]"
              << ", ";
    std::cout << "" << std::endl;
}

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans = {};
        ans.push_back({});
        for (int i = 0; i < nums.size(); i++)
        {
            int target = nums[i];
            vector<vector<int>> subsets = {};
            for (auto v : ans)
            {
                v.push_back(target);
                subsets.push_back(v);
            }
            for (auto sub : subsets)
            {
                ans.push_back(sub);
            }
        }

        return ans;
    }
};

int main()
{
    Solution *solver = new Solution();

    vector<int> v1 = {1, 2, 3, 4};
    vector<vector<int>> ans = solver->subsets(v1);

    for (auto array : ans)
    {
        print_vec(array);
    }

    return 0;
}
