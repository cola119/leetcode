class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, int> map;
        vector<vector<string>> ans;
        for (auto str : strs)
        {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            if (map.find(sorted) == map.end())
            {
                vector<string> array;
                array.push_back(str);
                ans.push_back(array);
                map.insert({sorted, ans.size() - 1});
            }
            else
            {
                auto pair = map.find(sorted);
                ans[pair->second].push_back(str);
            }
        }
        return ans;
    }
};