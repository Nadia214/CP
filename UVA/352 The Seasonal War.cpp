#include<bits/stdc++.h>
using namespace std;

char image[30][30];
bool visited[30][30];

int dx[]= {0,0,1,1,-1,-1,1,-1}; //For 8 direction
int dy[]= {1,-1,1,-1,1,-1,0,0};
int n;

bool isValid(int x, int y)
{
    return x >= 0 && x<n && y>=0 && y<n && !visited[x][y];
}

void dfs(int i, int  j)
{

    visited[i][j] = 1;
    for(int k = 0; k < 8; k++)
    {
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if(image[i][j] == image[nx][ny] && isValid(nx,ny))
        {
            dfs(nx,ny);
        }
    }
}
int main()
{

    int cs = 1;
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            char ch ;
            scanf("%s",image[i]);
        }

        int components = 0;
        memset(visited, 0, sizeof visited);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <n; j++)
            {
                if(image[i][j] == '1' && !visited[i][j])
                {
                    components++;
                    dfs(i,j);
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n",cs++, components);
    }
    return 0;
}

