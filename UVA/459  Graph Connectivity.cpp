#include<bits/stdc++.h>
using namespace std;

int parent[26];
int rank_p[26];
void makeSet()
{
    for(int i = 0; i < 26; i++)
    {
        parent[i] = i;
        rank_p[i] = 0;
    }
}



int findParent(int x)
{
    return (x == parent[x] ? x : parent[x] = findParent(parent[x]));
}


void unionSet(int x, int y)
{
    x = findParent(x);
    y = findParent(y);

    if (x == y)
        return;

    if (rank_p[x] > rank_p[y])
        parent[y] = x;
    else
    {
        parent[x] = y;
        if (rank_p[x] == rank_p[y])
            rank_p[y]++;
    }
}
int main()
{

    int  T;
    cin >> T;
    cin.ignore(1024,'\n');

    string line;
    getline(cin, line);

    for(int i = 1; i <= T; i++)
    {

        if(i > 1)cout<<endl;

        makeSet();
        int maxIndex = 0;
        while(getline(cin,line),line.length() > 0)
        {
            if(line.length() == 1)
            {
                maxIndex = line.front() - 'A';
                continue;
            }
            for(int i = 1; i < line.length(); i++)
            {
                unionSet(line[1] - 'A', line.front() - 'A');
            }

        }

        int counter = 0;
        for(int i = 0; i <= maxIndex; i++)
        {
            if(i == parent[i])
            {
                counter++;
               // cout<<i<<endl;
            }
        }

        cout<<counter<<endl;

    }

    return 0;
}
