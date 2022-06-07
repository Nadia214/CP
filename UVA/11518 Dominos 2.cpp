#include<bits/stdc++.h>
using namespace std;

vector<int>dominos[10010];
bool visited[10010];

int cnt;
void dfs(int u)
{
    cnt++;
    visited[u] = 1;
    for(auto v : dominos[u])
    {
        if(!visited[v])
            dfs(v);
    }
}

int main()
{

    int cases;
    cin >> cases;

    for(int c = 1; c <= cases; c++)
    {

        int n,m,l,z;
        cin >> n >> m >> l;
        for(int i = 1; i <= n; i++)
        {
            dominos[i].clear();
        }

        for(int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            dominos[u].push_back(v);
        }
        cnt = 0;
        memset(visited, 0, sizeof visited);
        for(int i = 1; i <= l; i++)
        {
            cin >> z;
            if(!visited[z])
                dfs(z);
        }

        cout << cnt << '\n';
    }

    return 0;

}
