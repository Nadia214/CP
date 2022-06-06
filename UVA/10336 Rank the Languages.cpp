#include<bits/stdc++.h>
using namespace std;

char grid[30][30];
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
int row, col;

struct language
{
    char letter;
    int number;

    bool operator<(const language &l)const
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
    int cases;
    cin>> cases;

    for(int c = 1; c <= cases; c++)
    {
        cin >> row >> col;

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
            }
        }

        map<char,int> cnt;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] != '.')
                {
                    cnt[grid[i][j]]++;
                    dfs(i,j);
                }
            }
        }
        vector<language>result;

        for(auto p : cnt)
        {
            result.push_back(language{p.first, p.second});
        }


        sort(result.begin(), result.end());

        cout<< "World #"<< c <<"\n";

        for(auto res : result)
            cout<<res.letter <<": "<<res.number<<'\n';

    }
    return 0;
}
