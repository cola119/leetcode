#include <cassert>
#include <cmath>
#include <iostream>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
            return true;

        int n = floor(log10(x));
        int x_i = 0;
        int pow_ten_i = 1;
        int a[n + 1];

        for (int i = 0; i <= n; i++)
        {
            a[i] = ((i < n ? x % (pow_ten_i * 10) : x) - x_i) / pow_ten_i;
            x_i += a[i] * (pow_ten_i == 1 ? 1 : pow_ten_i / 10);
            if (i < n)
            {
                pow_ten_i *= 10;
            }
        }

        for (int i = 0; i <= floor(n / 2); i++)
        {
            int j = n - i;
            if (a[i] != a[j])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution *solver = new Solution();

    assert(solver->isPalindrome(0) == true);
    assert(solver->isPalindrome(1) == true);
    assert(solver->isPalindrome(2) == true);
    assert(solver->isPalindrome(121) == true);
    assert(solver->isPalindrome(-121) == false);
    assert(solver->isPalindrome(10) == false);
    assert(solver->isPalindrome(1234567899) == true);

    return 0;
}