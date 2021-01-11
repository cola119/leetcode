#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        if (x == -2147483648)
            return 0;
        bool minus = x < 0;
        x = minus ? -x : x;
        int ans = 0;
        while (x > 0)
        {
            int r = x % 10;
            if (INT32_MIN / 10 > ans || (INT32_MIN / 10 == ans && INT32_MIN % 10 > r))
            {
                return 0;
            }
            if (INT32_MAX / 10 < ans || (INT32_MAX / 10 == ans && INT32_MAX % 10 < r))
            {
                return 0;
            }
            ans = ans * 10 + r;
            x = (x - r) / 10;
        }
        return minus ? -ans : ans;
    }
};

int main()
{
    Solution *solver = new Solution();

    int ans = solver->reverse(1463847412);

    std::cout << ans << std::endl;
    assert(ans == 2147483641);

    return 0;
}