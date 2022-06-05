#include<bits/stdc++.h>
using namespace std;

char grid[25][25];
int dx[]= {1,-1,0,0,1,-1,1,-1};
int dy[]= {0,0,1,-1,1,1, -1,-1};

int blob,row,col;

bool valid(int i, int j)
{
    return i >= 0 && j>=0 && i< row && j <col;
}

void dfs(int x, int y)
{

    grid[x][y] = '*';
    blob++;
    for(int k = 0; k <8; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(valid(nx, ny) & grid[nx][ny] == '1')
        {
            dfs(nx,ny);
        }
    }
}

int main()
{
    string line;
    int largest_blob;
    getline(cin, line);
    int T = stoi(line);
    getchar();

    for(int i = 1; i<= T; i++)
    {

        if(i > 1) cout<<'\n';

        memset(grid, 0, sizeof grid);

        largest_blob = 0;
        row = 0;

        while(getline(cin, line), line.length() > 0)
        {
            for(int j = 0; j < line.length(); j++)
            {
                grid[row][j] = line[j];
            }
            row++;
            col = line.length();
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    blob = 0;
                    dfs(i,j);
                    largest_blob = max(blob, largest_blob);
                }
            }
        }

        cout<<largest_blob<<'\n';

    }

    return 0;
}
