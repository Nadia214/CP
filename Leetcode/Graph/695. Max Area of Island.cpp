//695. Max Area of Island
class Solution {
public:
    int row, col;
    void dfs(int i, int j, vector<vector<int>>& grid, int &area) {
        if(i < 0 || j < 0 || i >= row || j >= col) return;
        if(!grid[i][j]) return;

        grid[i][j] = 0;
        area++;

        dfs(i + 1, j, grid, area);
        dfs(i - 1, j, grid, area);
        dfs(i, j + 1, grid, area);
        dfs(i, j - 1, grid, area);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        row = grid.size();
        col = grid[0].size();
        int area;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]){
                    area = 0;
                    dfs(i, j, grid, area);
                    maxArea = max(area, maxArea);
                }
            }
        }
     return maxArea;
    }
};
