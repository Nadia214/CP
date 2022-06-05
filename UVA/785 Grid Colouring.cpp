#include<bits/stdc++.h>
using namespace std;

string maze[40];
bool visited[40][100];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool isValid(int i, int j)
{
    return  i >= 0 && i< 40 && j >= 0 && j < 100  &&!visited[i][j];
}

void dfs(int x, int y, char ch)
{

    visited[x][y] = 1;
    maze[x][y] = ch;

    for(int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if(isValid(nx,ny) && maze[nx][ny] == ' ')
        {

            dfs(nx,ny,ch);
        }

    }
}
int main()
{

    while(true)
    {
        memset(visited, 0, sizeof visited);
        int row = 0;
        while(true) {
            if(!getline(cin,maze[row])) return 0;
            if(maze[row][0] == '_')break;
            row++ ;
        }


        for(int i = 0; i < row; i++ ){
            int col = maze[i].size();
            for(int j = 0; j< col; j++){
                if(maze[i][j] != 'X' && maze[i][j]!= ' ' && !visited[i][j]){
                  dfs(i,j, maze[i][j]);

                }
            }
        }


       for(int i = 0 ; i < row ; i++) {
            cout << maze[i] << "\n" ;
            maze[i].clear() ;
        }
        cout << "_____________________________\n" ;



    }
    return 0;

}
