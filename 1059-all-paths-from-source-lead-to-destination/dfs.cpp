class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> visited(n, -1);
        for(auto edge: edges) graph[edge[0]].push_back(edge[1]);
        return dfs(graph, visited, source, destination);
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i, int destination) {
        if(graph[i].empty()) return i == destination;
        if(visited[i] != -1) return visited[i];
        visited[i] = 0;
        for(auto e: graph[i]) {
            if(!dfs(graph, visited, e, destination)) return false;
        }
        visited[i] = 1;
        return true;
    }
};