#include <vector>
#include <iostream>

using namespace std;
int gcd(int i, int j);

// 配列を border 個だけ左に動かす
// [1,2,3,4,5], border: 3
// -> [4,5,1,2,3]
vector<int> rotateVector(vector<int> &nums, int border)
{
    int n = nums.size();
    for (int i = 0; i < gcd(n, border); i++)
    {
        int t = nums[i];
        int j = i;
        while (true)
        {
            int k = j + border;
            if (k >= n)
            {
                k -= n;
            }
            if (k == i)
            {
                break;
            }
            nums[j] = nums[k];
            j = k;
        }
        nums[j] = t;
    }

    return nums;
}

int gcd(int i, int j)
{
    while (i != j)
    {
        if (i > j)
        {
            i -= j;
        }
        else
        {
            j -= i;
        }
    }
    return i;
}

void printVec(vector<int> &nums)
{
    cout << "[";
    for (auto num : nums)
    {
        cout << num << ",";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    auto res = rotateVector(nums, 3);
    printVec(res);
    nums = {1, 2, 3, 4, 5, 6};
    res = rotateVector(nums, 3);
    printVec(res);
    nums = {1, 2, 3, 4, 5, 6};
    res = rotateVector(nums, 1);
    printVec(res);
    nums = {1, 2, 3, 4};
    res = rotateVector(nums, 3);
    printVec(res);
    return 0;
}