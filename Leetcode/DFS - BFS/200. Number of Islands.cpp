//200. Number of Islands
//TC- O(M*N) where M = row; N = col
//SC- O(M*N)
class Solution {
public:
    void dfs(int i, int j,vector<vector<char>>& grid) {

        if(i < 0 || i >= grid.size() || j <0 || j >= grid[0].size())
            return;
        if(grid[i][j] == '0' || grid[i][j] == '2') return;

        grid[i][j] = '2';

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);

    }

    int numIslands(vector<vector<char>>& grid) {
       int islands = 0;
       int row = grid.size();
       int col = grid[0].size();
       for(int i = 0; i < row; i++) {
           for(int j = 0;  j  < col; j++){
               if(grid[i][j] == '1'){
                   islands++;
                   dfs(i, j, grid);
               }
           }
       }
    return islands;
    }
};
