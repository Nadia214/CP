#include<bits/stdc++.h>
using namespace std;

vector<int>graph[30];
bool visited[30];

void dfs(int u)
{
    visited[u] = 1;
    for(auto v: graph[u])
    {

        if(!visited[v])
        {
            dfs(v);
        }
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

        if(i > 1)puts("");

        int maxIndex = 0;
        while(getline(cin,line),line.length() > 0)
        {
            if(line.length() == 1)
            {
                maxIndex = line.front() - 'A';
                continue;
            }
            graph[line[0] - 'A'].push_back(line[1] - 'A');
            graph[line[1] - 'A'].push_back(line[0] - 'A');

        }

        int counter = 0;
        for(int i = 0; i <= maxIndex; i++)
        {
            if(!visited[i])
            {
                counter++;
                dfs(i);
            }
        }


        cout<<counter<<endl;

    }

    return 0;
}
