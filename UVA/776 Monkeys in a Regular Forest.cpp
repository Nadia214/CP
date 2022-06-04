#include<bits/stdc++.h>
using namespace std;

char forest[1010][1010];
bool visited[1010][110];
int maze[1010][1010];


int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int row = 0,col = 0,cnt;

bool isValid(int x, int y)
{
    return x >= 0 && x < row && y>= 0 && y<col && !visited[x][y];
}

void dfs(int i, int j, int rnk)
{
    visited[i][j] = 1;
    maze[i][j] = rnk;

    for(int k = 0; k < 8; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(isValid(nx,ny) && forest[nx][ny] == forest[i][j])
        {
            dfs(nx,ny,rnk);

        }

    }
}

int Max_Spaces(int col)
{
    int T = -1;

    for (int i = 0; i < row; i++)
        T = max(T, maze[i][col]);

    return  1 + log10(T*1.0);
}

void solve()
{

    memset(visited, 0, sizeof visited);

    //forest.clear();

    int n = 1;

    for(int i = 0; i <row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(!visited[i][j])
            {

                dfs(i, j, n),
                    n++;

            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << setw(Max_Spaces(j)) << right << maze[i][j];
            if (j != col - 1)
                cout << " ";
        }
        cout << endl;
    }
    cout << "%" << endl;

}
int main()
{
    string line;
    memset(forest, 0, sizeof forest);
    while(getline(cin,line), line.length() > 0)
    {
        if (line != "%")
        {
            col = 0;
            for (int i = 0; i < line.length(); i++)
            {
                if (isalpha(line[i]))
                {
                    forest[row][col] = line[i];
                    col++;
                }
            }
            row++;
            continue;
        }

        solve();
        row = 0;

    }

    solve();

    return 0;
}
