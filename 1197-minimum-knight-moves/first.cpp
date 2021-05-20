class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        
        if(x == 1 && y == 1) return 2;
        
        vector<pair<int, int>> moves;
        moves.push_back(pair(1,2));
        moves.push_back(pair(1,-2));
        moves.push_back(pair(2,1));
        moves.push_back(pair(2,-1));
        moves.push_back(pair(-1,2));
        moves.push_back(pair(-1,-2));
        moves.push_back(pair(-2,1));
        moves.push_back(pair(-2,-1));
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0}, 0});
        
        vector<vector<int>> visited(301, vector<int>(301, 0));
        visited[0][0] = 1;

        while(!q.empty()) {
            auto pair = q.front(); q.pop();
            auto loc = pair.first;
            int cnt = pair.second;
            if(loc.first == x && loc.second == y) return cnt;
            for(auto move: moves) {
                int nx = loc.first + move.first;
                int ny = loc.second + move.second;
                if(nx >= 0 && ny >= 0 && nx <= 300 && ny <= 300 && visited[nx][ny] == 0) {
                    q.push({{nx,ny}, cnt+1});
                    visited[nx][ny] = 1;
                }
            }
        }
        
        return 0;
    }
    
    int abs(int a) {
        return a < 0 ? -a : a;
    }
};