class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 1)
            return target == nums[0] ? 0 : -1;
        if (n == 2)
            return target == nums[0] ? 0 : target == nums[1] ? 1
                                                             : -1;
        return binary_search(nums, target, 0, nums.size() - 1);
    }

    int binary_search(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
            return -1;
        int center = std::ceil((left + right) / 2);

        if (target == nums[center])
            return center;

        bool pivot = (center - 1 >= 0 && center + 1 < nums.size()) ? nums[center - 1] > nums[center + 1] : false;
        if (target < nums[center])
        {
            int res = binary_search(nums, target, left, center - 1);
            return res > -1 ? res : binary_search(nums, target, center + 1, right);
        }
        else
        {
            int res = binary_search(nums, target, center + 1, right);
            return res > -1 ? res : binary_search(nums, target, left, center - 1);
        }
    }
};