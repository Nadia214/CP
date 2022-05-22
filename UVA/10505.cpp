
#include <bits/stdc++.h>

using namespace std;

const int BLACK = 0, WHITE = 1;
int n, m, total, blacks, visited[210], bipartite;
vector<int> graph[210];
int clr[210];
void dfs(int u, int color)
{
    visited[u] = 1;
    clr[u] = color;
    total++;
    if (color == BLACK) blacks++;
    for (auto v : graph[u])
    {
        if (!visited[v])
        {
            dfs(v, 1 ^ color );
        }
        else if (clr[v] == color)
        {
            bipartite = 0;
        }
    }
}

int main()
{
    //cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases;
    cin >> cases;
    for (int c = 1; c <= cases; c++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            graph[i].clear();

        for (int u = 1, v; u <= n; u++)
        {
            cin >> m;
            for (int j = 1; j <= m; j++)
            {
                cin >> v;
                if (v > n) continue;
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }

        int invited = 0;
        memset(visited, 0 , sizeof(visited));
        memset(clr, 0 , sizeof(clr));
        for (int i = 1; i <= n; i++)
            if (!visited[i])
            {
                total = blacks = 0, bipartite = 1;
                dfs(i, BLACK);
                if (bipartite) invited += max(blacks, total - blacks);
            }
        cout << invited << '\n';
    }

    return 0;
}
