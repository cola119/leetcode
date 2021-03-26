class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<int, pair<int, int>>> q;
        for (auto num1 : nums1)
        {
            for (auto num2 : nums2)
            {
                pair<int, pair<int, int>> p = {num1 + num2, {num1, num2}};
                q.push(p);
                if (q.size() > k)
                {
                    q.pop();
                }
            }
        }
        vector<vector<int>> ans;
        while (!q.empty())
        {
            auto p = q.top();
            pair<int, int> data = p.second;
            vector<int> v = {data.first, data.second};
            ans.push_back(v);
            q.pop();
        }
        return ans;
    }
};