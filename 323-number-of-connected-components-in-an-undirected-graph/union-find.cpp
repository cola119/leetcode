class Solution
{
    vector<int> parent;
    vector<int> size;

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        size = vector<int>(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto edge : edges)
        {
            merge(edge[0], edge[1]);
        }

        unordered_set<int> set;
        for (int i = 0; i < n; i++)
        {
            set.insert(root(i));
        }
        return set.size();
    }

    int root(int x)
    {
        if (x == parent[x])
            return x;
        return root(parent[x]);
    }

    void merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;
        if (size[x] < size[y])
            swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};
