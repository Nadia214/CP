#include<bits/stdc++.h>
using namespace std;

char grid[30][30];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
int row, col, counter;


bool isValid (int x)
{

    return x >= 0 && x < row ;

}

int fix(int y){

  if(y < 0) return col - 1;
  if(y >= col) return 0;
  return y;

}
void dfs(int i, int j)
{

    char ch = grid[i][j];
    grid[i][j] = '.';
    counter++;
    for(int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = fix(j + dy[k]);

        if(isValid(nx) && grid[nx][ny] == ch)
        {
            dfs(nx,ny);
        }
    }
}


int main()
{

    while(cin>>row>>col)
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
            }
        }

        int X,Y;
        cin >> X >> Y;

        char land = grid[X][Y];

        dfs(X, Y);

        int maxLand = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == land)
                {
                    counter = 0;
                    dfs(i,j);
                    maxLand = max(maxLand, counter);
                }
            }
        }


        cout<< maxLand<<"\n";

    }
    return 0;
}
