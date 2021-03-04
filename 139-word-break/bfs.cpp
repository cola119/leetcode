class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        queue<int> q;
        q.push(0);
        vector<bool> visited(s.length(), false);
        while (!q.empty())
        {
            int start = q.front();
            q.pop();
            if (visited[start])
                continue;
            for (int end = start + 1; end <= s.size(); end++)
            {
                if (wordSet.find(s.substr(start, end - start)) != wordSet.end())
                {
                    if (end == s.size())
                        return true;
                    q.push(end);
                }
            }
            visited[start] = true;
        }
        return false;
    }
};