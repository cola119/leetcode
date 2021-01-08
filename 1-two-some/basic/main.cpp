#include <iostream>
#include <vector>
using namespace std;

vector<int> calc(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if (i == j)
            {
                continue;
            }

            if ((nums[i] + nums[j]) == target)
            {
                return {i, j};
            }
        }
    }

    return {0, 0};
}

int main()
{
    vector<int> vec1 = {3, 2, 4};
    auto result = calc(vec1, 6);
    assert(result[0] == 1);
    assert(result[1] == 2);

    std::cout << "done" << std::endl;

    return 0;
}
