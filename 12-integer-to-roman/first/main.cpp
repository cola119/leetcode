#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        int dividers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string s = "";
        for (int divider : dividers)
        {
            if (num <= 0)
                break;
            int a = num / divider;
            if (a == 0)
                continue;
            num -= a * divider;
            for (int i = 0; i < a; i++)
            {
                s += romanStr(divider);
            }
        }
        return s;
    }

    string romanStr(int num)
    {
        if (num == 1000)
            return "M";
        if (num == 900)
            return "CM";
        if (num == 500)
            return "D";
        if (num == 400)
            return "CD";
        if (num == 100)
            return "C";
        if (num == 90)
            return "XC";
        if (num == 50)
            return "L";
        if (num == 40)
            return "XL";
        if (num == 10)
            return "X";
        if (num == 9)
            return "IX";
        if (num == 5)
            return "V";
        if (num == 4)
            return "IV";
        if (num == 1)
            return "I";

        return "";
    }
};

int main()
{
    Solution *solver = new Solution();
    assert(solver->intToRoman(3) == "III");
    assert(solver->intToRoman(4) == "IV");
    assert(solver->intToRoman(58) == "LVIII");
    assert(solver->intToRoman(1994) == "MCMXCIV");

    return 0;
}