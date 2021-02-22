class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        bool oneIsSmall = n < m;
        unordered_set<int> set;
        unordered_set<int> ans;
        for (int i = 0; i < min(n, m); i++)
        {
            set.insert(oneIsSmall ? nums1[i] : nums2[i]);
        }
        for (int i = 0; i < max(n, m); i++)
        {
            auto target = !oneIsSmall ? nums1[i] : nums2[i];
            if (set.find(target) != set.end())
            {
                ans.insert(target);
            }
        }
        vector<int> ans_vec;
        for (auto v : ans)
        {
            ans_vec.push_back(v);
        }
        return ans_vec;
    }
};