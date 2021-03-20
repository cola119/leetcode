class KthLargest
{
private:
    int size;
    priority_queue<int, vector<int>, greater<int>> q;

public:
    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (auto n : nums)
        {
            q.push(n);
            if (q.size() > k)
                q.pop();
        }
    }

    int add(int val)
    {
        q.push(val);
        if (q.size() > size)
            q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */