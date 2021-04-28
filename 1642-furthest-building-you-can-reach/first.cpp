struct MyPriorityQueue: std::priority_queue<int, std::vector<int>, std::less<int>> {
    auto begin() const { return c.begin(); }
    auto end() const { return c.end(); }
};

class Solution {
public:
    // [4,2,7,6,9,14,12]
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int prev = heights[0];
        for(int i = 0; i < heights.size(); i++) {
            int tmp = heights[i];
            heights[i] = tmp - prev;
            prev = tmp;
        }
        MyPriorityQueue current;
        for(int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            if(h > 0) {
                current.push(h);
            }
            // if(current.size() <= ladders) continue;
            int remain = bricks;
            int cnt = 0;
            for(auto &v: current) {
                if(cnt < ladders) {
                    cnt++;
                    continue;
                }
                remain -= v;
                if(remain < 0) return i-1;
            }
            if(remain >= 0) continue;
            else return i-1;
        }
        return heights.size()-1;
    }
};