#include<bits/stdc++.h>
using namespace std;



char grid[100][100];

int dx[]= {1,1,1,-1,-1,-1,0,0};
int dy[]= {1,0,-1,1,0,-1,1,-1};

int m,n;


bool isValid(int x,int y)
{


    return (x>=0 && x<m && y>=0 && y<n &&  grid[x][y]=='@');

}

       void dfs(int x,int y)
{


    grid[x][y] = '*';

    for(int j = 0; j<8; j++)
    {

        int nx = x +dx[j];
        int ny = y+dy[j];
        if(isValid(nx, ny))
        {
            dfs(nx, ny);
        }
    }





}


int main()
{


while(scanf("%d %d",&m,&n) && (m || n)){




    for(int i=0; i<m; i++)
        {

            for(int j = 0; j<n ; j++)
            {

                cin>>grid[i][j];


            }



        }
        int count =0;
        for(int i =0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(isValid(i, j))
                {
                    dfs(i, j);
                    count++;
                }
            }
        }

        cout<<count<<"\n";






    }



    return 0;

}
