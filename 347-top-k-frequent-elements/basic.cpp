class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            auto cnt = map.find(nums[i]);
            if (cnt == map.end())
            {
                map.insert({nums[i], 1});
            }
            else
            {
                cnt->second++;
            }
        }
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            pair<int, int> max_pair;
            int max_val = INT32_MIN;
            for (auto mp : map)
            {
                if (mp.second > max_val)
                {
                    max_val = mp.second;
                    max_pair = mp;
                }
            }
            map.erase(max_pair.first);
            res.push_back(max_pair.first);
        }
        return res;
    }
};