#include <cassert>
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
        if (x % 10 == 0)
            return false;

        int rev_x = 0;
        while (x > rev_x)
        {
            rev_x = rev_x * 10 + x % 10;
            x /= 10;
        }

        return x == rev_x || x == rev_x / 10;
    }
};

int main()
{
    Solution *solver = new Solution();

    assert(solver->isPalindrome(0) == true);
    assert(solver->isPalindrome(1) == true);
    assert(solver->isPalindrome(2) == true);
    assert(solver->isPalindrome(121) == true);
    assert(solver->isPalindrome(4114) == true);
    assert(solver->isPalindrome(-121) == false);
    assert(solver->isPalindrome(10) == false);
    assert(solver->isPalindrome(1234567899) == false);

    return 0;
}