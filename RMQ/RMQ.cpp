#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
struct RMQ
{
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> data;
    RMQ(int n_) : n(), data(n_ * 4, INF)
    {
        int x = 1;
        while (n_ > x)
        {
            x *= 2;
        }
        n = x;
    }

    void update(int i, T val)
    {
        i += n - 1;
        data[i] = val;
        while (i > 0)
        {
            i = (i - 1) / 2;
            data[i] = min(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    T get_min(int left, int right)
    {
        return get_min_sub(left, right, 0, 0, n);
    }
    T get_min_sub(int left, int right, int k, int l, int r)
    {
        if (right <= l || r <= left)
        {
            return INF;
        }
        if (left <= l && r <= right)
        {
            return data[k];
        }
        int vl = get_min_sub(left, right, k * 2 + 1, l, (l + r) / 2);
        int vr = get_min_sub(left, right, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int main()
{
    RMQ<int> rmq = {8};
    rmq.update(0, 3);
    rmq.update(1, 5);
    rmq.update(2, 2);
    rmq.update(3, 11);
    rmq.update(4, 9);
    rmq.update(5, 1);
    rmq.update(6, 20);
    rmq.update(7, 8);
    std::cout << rmq.get_min(0, 10) << std::endl;
    std::cout << rmq.get_min(2, 4) << std::endl;
    std::cout << rmq.get_min(1, 5) << std::endl;
    std::cout << rmq.get_min(1, 6) << std::endl;

    return 0;
}