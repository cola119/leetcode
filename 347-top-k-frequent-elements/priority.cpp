class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            map[nums[i]]++;
        }
        auto comp = [&map](int a, int b) {
            return map[a] < map[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);

        for (auto mp : map)
        {
            heap.push(mp.first);
        }
        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = heap.top();
            heap.pop();
        }
        return ans;
    }
};