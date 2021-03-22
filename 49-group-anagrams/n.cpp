class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (auto str : strs)
        {
            string key = sortStr(str);
            map[key].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto data : map)
        {
            ans.push_back(data.second);
        }
        return ans;
    }

    string sortStr(string str)
    {
        string t = "";
        vector<int> counter(26, 0);
        for (auto s : str)
        {
            counter[s - 'a']++;
        }
        for (int c = 0; c < 26; c++)
        {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};