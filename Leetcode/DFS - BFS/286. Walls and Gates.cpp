//286. Walls and Gates
//TC - O(N*M) where N is number of row, M is column
//sc -
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        if(n == 0) return;
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
   	            if(rooms[i][j] == 0)
                q.push({i, j});
            }
        }
        int dir[] = {0, 1, 0, -1, 0};
        while(!q.empty()) {
	        auto u = q.front();
            q.pop();
            for(int i  = 0; i < 4; i++) {
                int nx = u.first + dir[i];
                int ny = u.second + dir[i + 1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    if(rooms[u.first][u.second] + 1 < rooms[nx][ny]) {
                        rooms[nx][ny] = rooms[u.first][u.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
};
