#include <vector>
using namespace std;
typedef long long ll;

class UnionFind
{
public:
    vector<ll> parent;
    vector<ll> size;

    UnionFind(ll size_) : parent(size_), size(size_, 1LL)
    {
        for (ll i = 0; i < size_; ++i)
            parent[i] = i; // 最初は自身が親
    }
    void init(ll size_)
    {
        parent.resize(size_);
        size.assign(size_, 1LL);
        for (ll i = 0; i < size_; ++i)
            parent[i] = i;
    }

    ll root(ll x)
    {
        if (parent[x] == x)
            return x;
        return root(parent[x]);
    }

    bool merge(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (size[x] < size[y])
            swap(x, y);
        size[x] += size[y]; // 大きい方にくっつけていく
        parent[y] = x;
        return true;
    }

    bool isSame(ll x, ll y)
    {
        return root(x) == root(y);
    }

    ll size(ll x)
    {
        return size[root(x)];
    }
};