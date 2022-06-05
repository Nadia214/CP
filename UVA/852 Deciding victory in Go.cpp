#include<bits/stdc++.h>
using namespace std;

int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

char grid[15][15];
bool black_r, white_r;
int counter;

bool valid(int i, int j)
{

    return i >=0 && i< 9 && j>=0 && j<9;
}


void dfs(int x, int y)
{

    if (valid(x,y))
    {
        if (grid[x][y] == '.')
        {
            counter++;
            grid[x][y] = '*';
            dfs(x + 1, y);
            dfs(x, y + 1);
            dfs(x - 1, y);
            dfs(x, y - 1);

        }
        else
        {
            if (grid[x][y] == 'X')
            {
                black_r = true;
                return;
            }
            else if (grid[x][y] == 'O')
            {
                white_r = true;
                return;
            }
        }
    }
}



int main()
{


    int T,black,white;
    cin>>T;

    while(T--)
    {
        black = 0;
        white = 0;

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j] == 'X')black++;
                if(grid[i][j] == 'O')white++;
            }
        }

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(grid[i][j] == '.')
                {
                    counter = 0;
                    black_r = false;
                    white_r = false;
                    dfs(i,j);
                    if(black_r && !white_r)
                        black += counter;
                    if(white_r && !black_r)
                        white += counter;
                }
            }
        }


        cout << "Black " << black << " White " << white << endl;



    }

    return 0;

}
