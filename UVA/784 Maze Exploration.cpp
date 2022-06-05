#include<bits/stdc++.h>
using namespace std;

char maze[35][85];
bool visited[35][85];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool isValid(int i, int j)
{
    return  i >= 0 && i<35 && j >= 0 && j < 85  &&!visited[i][j];
}

void dfs(int x, int y)
{

    visited[x][y] = 1;
    maze[x][y] = '#';

    for(int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(isValid(nx,ny) && maze[nx][ny] != 'X')
        {

            dfs(nx,ny);
        }

    }
}
int main()
{

    int T;
    cin >> T;
    getchar();
    string line;
    for(int i = 1; i <= T; i++)
    {

        memset(maze, ' ', sizeof(maze));
        memset(visited, 0, sizeof visited);
        int row = 0, x = 0, y = 0, col = 0;
        while (getline(cin, line), line.front() != '_')
        {
            int i = 0;

            for (; i < line.length(); i++)
            {
                maze[row][i] = line[i];
                if (line[i] == '*')
                {
                    x = row, y = i;
                }

            }

            maze[row][i] = '\n';
            row++;
        }

        dfs(x,y);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < 85; j++)
            {
                cout << maze[i][j];
                if (maze[i][j] == '\n')
                    break;
            }

        }
        cout << line << '\n';


    }
    return 0;

}
