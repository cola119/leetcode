#include <vector>
#include <iostream>
#include <cmath>

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
    vector<int> int_to_bit(int num, int size)
    {
        vector<int> res(size);
        for (int i = 0; i < size; i++)
        {
            res[size - 1 - i] = num % 2;
            num /= 2;
        }

        return res;
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < pow(2, n); i++)
        {
            vector<int> bitmask = int_to_bit(i, n);
            vector<int> subset = {};
            for (int j = 0; j < bitmask.size(); j++)
            {
                if (bitmask[j] == 1)
                {
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
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
