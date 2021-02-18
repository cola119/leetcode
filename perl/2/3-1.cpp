#include <vector>
#include <iostream>

using namespace std;

// 配列を border 個だけ左に動かす
// [1,2,3,4,5], border: 3
// -> [4,5,1,2,3]
vector<int> rotateVector(vector<int> &nums, int border)
{
    int tmp = nums[0];
    int n = nums.size();
    int i = 0;
    int itr_cnt = 0;
    int j = border;

    int sum = n * (n - 1) / 2;

    while (sum > 0)
    {
        sum -= i;
        nums[i] = nums[j];
        i = j;
        j += border;
        if (j >= n)
        {
            j %= n;
        }
        if (j == itr_cnt)
        {
            nums[i] = tmp;
            sum -= i;
            itr_cnt++;
            tmp = nums[itr_cnt];
            i = itr_cnt;
            j = border + itr_cnt;
        }
    }

    return nums;
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