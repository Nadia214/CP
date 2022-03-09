#include<bits/stdc++.h>
using namespace std;

char grid[25][25];
bool visited[25][25];

int dx[] = {0,0,-1,+1};
int dy[] = {1,-1,0,0};

int ans,row,col;


int BFS(int sx, int sy)
{

    queue<pair<int,int>> q;
    q.push({sx,sy});
    visited[sx][sy] = 1;

    while(!q.empty())
    {

        pair<int,int> u = q.front();
        q.pop();

        for(int i = 0; i<4; i++)
        {

            int nx = u.first + dx[i];
            int ny = u.second + dy[i];

            if(nx>=0 && nx<row && ny>=0 && ny<col &&
                    !visited[nx][ny] && grid[nx][ny] != '#')
            {
                q.push({nx,ny});
                ans++;
                visited[nx][ny] = 1;
            }

        }



    }



    return ans;

}

int main()
{

    int T,cs = 1;
    cin>>T;

    while(T--)
    {

        memset(visited, 0, sizeof(visited));
        cin>>col>>row;
        int sx,sy;
        ans = 1;
        for(int i = 0; i<row ; i++)
        {
            for(int j = 0; j<col ; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j] == '@')
                {

                    sx = i;
                    sy = j;
                }
            }
        }


        ans = BFS(sx,sy);
      //  printf("Case %d: %d\n",cs++,ans);
        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }

    return 0;
}
