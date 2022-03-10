#include<bits/stdc++.h>
using namespace std;


char town_grid[25][25];
bool visited[25][25];
int dist[25][25];

int dx[] = {0,0,-1,+1};
int dy[] = {1,-1,0,0};

int row,col;
void BFS(int x,int y)
{

    memset(visited,0,sizeof(visited));
    memset(dist,0,sizeof(dist));

    queue<pair<int,int>>q;
    q.push({x, y});
    visited[x][y] = 1;


    while(!q.empty())
    {

        pair<int,int> u = q.front();
        q.pop();

        for(int i = 0; i<4; i++)
        {

            int nx = u.first + dx[i];
            int ny = u.second + dy[i];

            if(nx>0 && nx<=row && ny>0 && ny <=col && !visited[nx][ny] && town_grid[nx][ny] != '#' && town_grid[nx][ny] !='m')
            {

                visited[nx][ny] = 1;
                dist[nx][ny] = dist[u.first][u.second] +1;
                q.push({nx,ny});

            }
        }


    }







}

int main()
{

    int T,cs = 1;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&row,&col);

        int home_x,home_y;
        for(int i = 1; i<=row; i++)
        {
            for(int j = 1; j<=col; j++)
            {
                //cin>>town_grid[i][j];
                scanf(" %c",&town_grid[i][j]);
                if(town_grid[i][j] == 'h')
                {
                    home_x = i;
                    home_y = j;
                }
            }
        }

        int max_time = 0;

        for(int i =1; i<= row; i++ )
        {
            for(int j = 1; j<= col; j++)
            {
                if(town_grid[i][j] =='a' || town_grid[i][j] == 'b' || town_grid[i][j] == 'c')
                {
                    BFS(i,j);
                    if(dist[home_x][home_y]>max_time)
                    {
                        max_time = dist[home_x][home_y];
                    }
                }
            }
        }



        printf("Case %d: %d\n",cs++,max_time);

    }



    return 0;
}
