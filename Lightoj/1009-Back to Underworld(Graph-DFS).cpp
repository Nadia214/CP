#include<bits/stdc++.h>
using namespace std;

vector<int>graph[20005];
bool visited[20005];
int colour[20005];

int black,white;
void dfs(int node,int clr)
{

    visited[node] = 1;
    colour[node] = clr;

    if(colour[node]==1)white++;
    if(colour[node]==0)black++;

    for(int adj : graph[node])
    {
        if(!visited[adj])
        {
            dfs(adj,clr^1);
        }

    }

    return;
}

int main()
{

    int T,Cs = 1;
    cin>>T;


    while(T--)
    {
        int fight;
        cin>>fight;


        for(int i = 1; i<= 20005; i++)
        {
            graph[i].clear();
        }

        int loop = -1;
        for(int i = 1; i<=fight ; i++)
        {

            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            loop =max(loop, max(u,v));
        }

        int ans = 0;

        memset(visited,0,sizeof(visited));
        for(int i = 1; i<= loop ; i++)
        {
            if(!visited[i] && !graph[i].empty())
            {
                dfs(i,0);
                ans += max(black,white);
                black = 0;
                white = 0;
            }
        }
        printf("Case %d: %d\n",Cs++,ans);
    }



    return 0;
}
