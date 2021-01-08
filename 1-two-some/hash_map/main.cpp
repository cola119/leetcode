#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> calc(vector<int> &nums, int target)
{
    unordered_map<int, int> dffAndIndexMap;
    for (int i = 0; i < nums.size(); ++i)
    {
        unordered_map<int, int>::iterator cacheOrNull = dffAndIndexMap.find(nums[i]);
        if (cacheOrNull != dffAndIndexMap.end())
        {
            return {i, cacheOrNull->second};
        }
        dffAndIndexMap.insert({target - nums[i], i});
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
