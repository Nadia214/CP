//733. Flood Fill
// TC - (N)
// SC - O(N)
class Solution {
public:
    void dfs(vector<vector<int>>& image,  int sr, int sc, int newColor, int initColor  )
    {
        int row = image.size();
        int col = image[0].size();
        if( sr < 0  || sr >= row || sc < 0 || sc >= col || image[sr][sc] == newColor || image[sr][sc] != initColor)
            return;

        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, newColor, initColor);
        dfs(image, sr - 1, sc, newColor, initColor);
        dfs(image, sr, sc + 1, newColor, initColor);
        dfs(image, sr, sc - 1, newColor, initColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int initColor = image[sr][sc];
        dfs(image, sr, sc, newColor, initColor);
        return image;
    }
};
