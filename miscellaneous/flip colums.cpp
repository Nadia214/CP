#include<iostream>
using namespace std;

int grid[20][20];
int N,M,K;
int maxRow = 0,counter;

void flip(int i)
{
    for(int j = 0; j < N; j++){
        grid[j][i] = 1 - grid[j][i];
    }
}

void solve(int K)
{

    if(K == 0)
    {
        int row = 0;
        for(int i = 0; i < N; i++)
        {
            counter = 0;
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 1)
                    counter++;
            }
            if(counter == M)row++;
        }
        if(row > maxRow)
            maxRow = row;
        return;
    }
    for(int i = 0; i < M; i++){
        flip(i);
        solve(K - 1);
        flip(i);
    }
}

int main()
{
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> grid[i][j];


    solve(K);
    cout << maxRow << endl;
}
