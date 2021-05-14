class Solution {
public:
    // sticks = [2,8,4,5] ->sort-> [2,4,5,8] ->cost(6)-> [6,5,8] ->sort-> [5,6,8] ->cost(11)-> [11,8]
    // the length of initial sticks: N
    // sort: O(NlogN)
    // Σk=N,2 klogk <= Σk^2  O(N^2) < c < O(N^3)
    
    // priory_queue pq;
    // sticks = [2,8,4,5] ->pqを作る(NlogN)-> [2,4,5,8] ->cost(6)(2logN)-> [6,5,8] ->insert(logN)-> [5,6,8] ->cost(11)-> [11,8]
    // NlogN + (N-1)logN => O(NlogN)
    // space O(N)
    
    // stick [1,8,3,5]
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto stick: sticks) pq.push(stick); // [1,3,5,8]
        int cost = 0;
        // size: 1 pq:[17]
        while(pq.size() > 1) {
            int a = pq.top(); pq.pop(); // 8
            int b = pq.top(); pq.pop(); // 9
            int c = a + b; // 17
            cost += c; // 0+4+9+17=30
            pq.push(c); // [17]
        }
        return cost; // 30
    }
};