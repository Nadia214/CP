#include<bits/stdc++.h>
using namespace std;

char land[110][110];
bool visited[110][110];


int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

int row,col,cnt;

bool isValid(int x, int y)
{
    return x >= 0 && x < row && y>= 0 && y<col && !visited[x][y];
}

void dfs(int i, int j)
{
    visited[i][j] = 1;
    for(int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(isValid(nx,ny) && land[nx][ny] == '0')
        {
            dfs(nx,ny);
        }

    }
    cnt++;
}

int main()
{

    int T;
    cin>>T;

    string line,r,c;
    getline(cin,line);

    for(int i = 1; i<= T; i++)
    {
        if(i > 1) cout<<'\n';

        cin>> r >> c;

        cin.ignore(1024,'\n');

        int cell_row = stoi(r);
        int cell_col = stoi(c);
        row = 0;
        memset(land, 0, sizeof land);

        while(getline(cin,line),line.length() > 0)
        {

            for(int i = 0; i < line.length(); i++)
                land[row][i] = line[i];

            row++;
            col = line.length();
        }


        cnt = 0;
        memset(visited, 0, sizeof visited);
        dfs(--cell_row,--cell_col);
        cout <<cnt<< '\n';


    }

    return 0;
}
