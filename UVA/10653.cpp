#include<bits/stdc++.h>
using namespace std;

bool vis[10000][10000];
int dis[10000][10000];
int dx[] = {0,0,-1,+1};
int dy[] = {+1,-1,0,0};

int row,col;


void bfs(int x, int y){


   queue<pair<int,int>> q;
   q.push({x,y});

   vis[x][y] =1;

   while(!q.empty()){

        pair<int,int> u = q.front();
        q.pop();

        for(int i =0 ;i<4; i++){
            int nx = u.first + dx[i];
            int ny = u.second + dy[i];

            if(nx>=0 && nx<row && ny>=0 && ny<col && !vis[nx][ny]){
                q.push({nx,ny});
                vis[nx][ny]=1;
                dis[nx][ny]=dis[u.first][u.second]+1;
               // cout<<dis[nx][ny]<<"\n";
            }
        }

   }



}


int main(){

  while(cin>>row>>col){
    if(row == 0 && col == 0)break;

    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));

    int bomrow;
    cin>>bomrow;

    for(int i = 0;i <bomrow; i++){
        int rownum,bomb;
        cin>>rownum>>bomb;

        for(int j = 0; j<bomb ;j++){
            int colnum;
            cin>>colnum;
            vis[rownum][colnum] = 1;
        }
    }

  int sx,sy,ex,ey;

  cin>>sx>>sy>>ex>>ey;

  bfs(sx,sy);

  cout<<dis[ex][ey]<<"\n";
  }


  return 0;
}
