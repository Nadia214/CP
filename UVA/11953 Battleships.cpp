#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

char grid[110][110];
int N, ship, sunk;

bool isValid(int x, int y)
{

    return x >= 0 && x < N && y >= 0 && y < N;

}

void dfs(int i, int j)
{

    if(grid[i][j] == 'x')ship++;
   // else sunk++;

    grid[i][j] = '.';
    for(int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(isValid(nx, ny))
        {
            if(grid[nx][ny] == 'x' || grid[nx][ny] == '@')
                dfs(nx, ny);
        }
    }
}

int main()
{

    int cases;
    cin >> cases;

    for(int c = 1; c <= cases; c++)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> grid[i][j];
            }
        }

        int alived = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(grid[i][j] == 'x' || grid[i][j] == '@')
                {
                    ship = 0;
                    //sunk = 0;
                    dfs(i, j);
                    if(ship > 0)alived++;
                }
            }
        }

        cout << "Case " << c <<": " << alived <<'\n';
    }


    return 0;
}
