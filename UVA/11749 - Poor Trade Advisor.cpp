#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[600];
int visited[600];

int counter, maxPpa;

void dfs(int src)
{
    visited[src] += 1;
    for(auto &a : graph[src])
    {
        if(a.second != maxPpa) continue;
        if(!visited[a.first])
        {
            if(a.second == maxPpa) counter++;
            dfs(a.first);
        }
    }
}
int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)break;

        maxPpa = INT_MIN;
        for(int i = 0; i < m; i++)
        {
            int u, v, cost;
            cin >> u >> v >> cost;
            graph[u].push_back({v,cost});
            graph[v].push_back({u,cost});
            maxPpa = max( maxPpa, cost);
        }

        int maxCity = 0;
        memset(visited, 0, sizeof visited);
        for(int i = 1; i <= n; i++)
        {
            counter = 0;
            if(!visited[i])
            {
                visited[i] = -1;
                dfs(i);
            }
            maxCity = max(maxCity, counter);
        }

        cout << maxCity << '\n';

        for(int i = 0; i <= n; i++)graph[i].clear();
    }

    return 0;
}
