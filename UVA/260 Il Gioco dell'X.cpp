#include<bits/stdc++.h>
using namespace std;

char board[210][210];
bool visited[210][210];

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};
int n;

bool isValid(int x, int y)
{
    return x >= 0 && x<n && y>=0 && y<n && !visited[x][y];
}

void dfs(int i, int  j)
{

    visited[i][j] = 1;
    for(int k = 0; k < 6; k++)
    {
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if(isValid(nx, ny) && board[i][j] == board[nx][ny])
        {
            dfs(nx,ny);
        }
    }
}
int main()
{

    int cs = 1;
    while(scanf("%d",&n), n)
    {
        for(int i = 0; i < n; i++)
        {
            char ch ;
            scanf("%s",board[i]);
        }

        bool ok = 0;
        memset(visited, 0, sizeof visited);

        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'w')
            {
                dfs(i,0);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(visited[i][n-1])
            {
                ok = 1;
                break;
            }
        }

        if(ok)
            printf("%d W\n",cs++);
        else
            printf("%d B\n",cs++);
    }
    return 0;
}
