#include<bits/stdc++.h>
using namespace std;

char grid[110][110];
int dx[]= {1,-1,0,0,-1,-1,1,1};
int dy[]= {0,0,1,-1,-1,1,-1,1};
int row,col, counter;

bool isValid(int x, int y)
{

    return x >= 0 && x <= row && y >= 0 && y <= col;

}

void dfs(int i, int j)
{

    counter++;
    int old = grid[i][j];
    grid[i][j] = '.';
    for(int k = 0; k < 8; k++)
    {

        int nx = i + dx[k];
        int ny = j + dy[k];
        if(isValid(nx, ny) && grid[nx][ny] == old )
        {
            dfs(nx, ny);
        }
    }
}

int main()
{

    while(cin >> row >> col)
    {

        if(row == 0 && col == 0)break;
        memset(grid, 0, sizeof grid);

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                cin >> grid[i][j];

        int stars = 0;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j <col; j++)
            {
                if(grid[i][j] == '*')
                {
                    counter = 0;
                    dfs(i, j);
                    if(counter == 1)stars++;

                }
            }
        }

        cout << stars << '\n';
    }
    return 0;
}
