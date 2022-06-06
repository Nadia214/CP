#include<bits/stdc++.h>
using namespace std;

int grid[110][110];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
int N, counter;

bool isValid(int x, int y)
{

    return x >= 1 && x <= N && y >= 1 && y <= N;

}

void dfs(int i, int j)
{

    counter++;
    int old = grid[i][j];
    grid[i][j] = 0;
    for(int k = 0; k < 4; k++)
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

    string line;
    while(cin >> N, N)
    {

        memset(grid, 0, sizeof grid);
        cin.ignore();

        int cnt = 1,x,y;
        for(int i = 1; i < N; i++)
        {
            getline(cin, line);
            stringstream ss(line);
            while(ss >>x >> y)
            {
                grid[x][y] = cnt;
            }
            cnt++;
        }
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (!grid[i][j])
                    grid[i][j] = cnt;



        bool ok = true;

        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(grid[i][j])
                {
                    counter = 0;
                    dfs(i, j);
                    if(counter != N)ok = false;

                }
            }
        }

        if(ok) cout<<"good"<<endl;
        else cout<<"wrong"<<endl;
    }
    return 0;
}
