class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> map;
        map.insert({0, 1});

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int diff = sum - k;
            if (map.find(diff) != map.end())
            {
                int _cnt = map.find(diff)->second;
                count += _cnt;
            }
            if (map.find(sum) != map.end())
            {
                map.find(sum)->second += 1;
            }
            else
            {
                map.insert({sum, 1});
            }
        }

        return count;
    }
};