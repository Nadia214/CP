//UVa 11504 - Dominos * (interesting problem: count |SCCs| without incoming edge from a vertex outside that SCC)
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100010];
bool visited[100010];
stack<int>stk;
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
    stk.push(u);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        while(!stk.empty())stk.pop();
        for(int i = 0; i<= n; i++)graph[i].clear();
        memset(visited, 0, sizeof visited);

        for(int i = 1; i<= m; i++)
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
        }

        for(int i = 1; i<= n; i++)
        {
            if(!visited[i])
            {
                dfs(i);
            }
        }

        int cnt = 0;
        memset(visited, 0, sizeof visited);
        while(!stk.empty())
        {
            int u = stk.top();
            if(!visited[u])dfs(u),cnt++;

            stk.pop();

        }

        cout<<cnt<<"\n";
    }

    return 0;

}
