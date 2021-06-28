class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, unordered_set<int>> map;
        if(edges.size() == 0) return source == destination;
        for(auto edge: edges) {
            if(map.find(edge[0]) == map.end()) {
                unordered_set<int> s;
                s.insert(edge[1]);
                map[edge[0]] = s;
            } else {
                map[edge[0]].insert(edge[1]);
            }
        }
        unordered_set<int> state = map[source];
        int cnt = 0;
        while(cnt <= n+1) {
            unordered_set<int> next_state;
            if(state.size() == 1 && state.find(destination) != state.end() && map.find(destination) == map.end()) {
                return true;
            }
            for(auto edge: state) {
                if(map.find(edge) != map.end()) {
                    for(auto e: map[edge]) {
                        next_state.insert(e);
                    }
                } else if(edge != destination) {
                    return false;
                }
            }
            state = next_state;
            cnt++;
        }
        return false;
    }
};