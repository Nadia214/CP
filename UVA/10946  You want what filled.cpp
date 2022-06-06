#include<bits/stdc++.h>
using namespace std;

char grid[50][50];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
int row, col, counter;

struct Holes
{
    char letter;
    int number;

    bool operator<(const Holes &l)const
    {
        if(number != l.number) return  number > l.number;
        return letter < l.letter;
    }
};

bool isValid (int x, int y)
{

    return x >= 0 && x < row &&  y >= 0 && y < col ;

}
void dfs(int i, int j)
{

    char ch = grid[i][j];
    grid[i][j] = '.';
    counter++;
    for(int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];

        if(isValid(nx,ny) && grid[nx][ny] == ch)
        {
            dfs(nx,ny);
        }
    }
}


int main()
{

    int CS = 1;
    while(cin>>row>>col)
    {
        if(row == 0 && col == 0)break;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
            }
        }

        vector<Holes> hole;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] != '.')
                {
                    counter = 0;
                    char ch = grid[i][j];
                    dfs(i,j);
                    hole.push_back(Holes{ch,counter});

                }
            }
        }


        sort(hole.begin(), hole.end());

        cout<< "Problem "<< CS++ <<":"<<"\n";

        for(auto h : hole)
            cout<<h.letter <<" "<<h.number<<'\n';

    }
    return 0;
}
