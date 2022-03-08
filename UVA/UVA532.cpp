#include<bits/stdc++.h>
using namespace std;
string str[32][32];
int dist[32][32][32];
int L,M,R;
int dx[]= {1,-1,0,0,0,0};
int dy[]= {0,0,1,-1,0,0};
int dz[]= {0,0,0,0,1,-1};

struct cell
{
   int x, y,z; cell(){}
   cell(int _x,int _y, int _z){
     x = _x;
     y = _y;
     z = _z;
   }

};

bool isValid(int x,int y,int z)
{
  return x>=0 && y>= 0 && z>= 0 && x<L && x<M && x<R && str[x][y][z] != '#';
}
int bfs(int sx, int sy,int sz, int ex, int ey, int ez)
{


    for(int i = 0; i<L ; i++)
    {
        for(int j = 0; j<M  ; j++)
        {
            for(int k = 0; k<R; k++)
            {
                dist[i][j][k] = INT_MAX;
            }
        }
    }

    dist[sx][sy][sz] = 0;
    queue<cell>q;
    q.push(cell(sx, sy, sz));

    while(!q.empty())
    {


        cell u = q.front();
        q.pop();

        for(int i = 0; i<6 ; i++)
        {
            cell v;
            v.x =u.x + dx[i];
            v.y =u.y + dy[i];
            v.z =u.z + dz[i];

            if(isValid(v.x,v.y,v.z) && (dist[v.x][v.y][v.z] > dist[u.x][u.y][u.z]+1))
            {

                dist[v.x][v.y][v.z] = dist[u.x][u.y][u.z]+1;
                q.push(v);

            }
        }

    }

    return dist[ex][ey][ez];
}


int main()
{

    while(cin >> L >> M >> R)
    {

        if(L == 0 && M == 0 && R==0)break;

        for(int i =0; i<L ; i++)
        {
            for(int j = 0; j<M ; j++)
            {
                cin >>str[i][j];
            }
        }

        int sx,sy,sz,ex,ey,ez;
        for(int i = 0; i<L ; i++)
        {
            for(int j = 0; j<  M ; j++)
            {
                for(int k = 0; k<R; k++)
                {
                    if(str[i][j][k]== 'S')
                    {
                        sx = i;
                        sy = j;
                        sz = k;
                    }
                    if(str[i][j][k]== 'E')
                    {
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }


        int res = bfs(sx, sy, sz, ex, ey, ez);

        if(res == INT_MAX)puts("Trapped!");
        else printf("Escaped in %d minute(s).\n",res);
    }

    return 0;
}
