#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        unordered_map<int, int> map;
        int ans = 0;

        for (int i = 0; i < height.size(); i++)
        {
            int h = height[i];
            for (int j = 1; j <= h; j++)
            {
                if (map.find(j) == map.end())
                {
                    map.insert({j, i});
                }
                else
                {
                    int k = map.find(j)->second;
                    ans = max(ans, (i - k) * j);
                }
            }
        }

        return ans;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};

int main()
{
    Solution *solver = new Solution();

    vector<int> v1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(solver->maxArea(v1) == 49);
    vector<int> v2 = {1, 1};
    assert(solver->maxArea(v2) == 1);
    vector<int> v3 = {4, 3, 2, 1, 4};
    assert(solver->maxArea(v3) == 16);
    vector<int> v4 = {1, 2, 1};
    assert(solver->maxArea(v4) == 2);

    return 0;
}