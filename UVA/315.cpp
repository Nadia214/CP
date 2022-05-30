// UVa 00315 - Network * (finding articulation points)
#include<bits/stdc++.h>
using namespace std;
vector<int>network[110];
int dfsNum[110];
bool artiVertices[110];
int low[110];
int parent[110];
int dfsroot, rchild, timer;

void dfs(int u)
{

    dfsNum[u] = low[u] = timer++;
    for(auto v: network[u])
    {

        if(!dfsNum[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
            parent[v] = u;
            if(u == dfsroot)
            {
                rchild++;
            }
            if(u != dfsroot && low[v] >= dfsNum[u])artiVertices[u] = 1;
        }

        else if(v != parent[u])
        {
            low[u] = min(low[u], dfsNum[v]);
        }
    }

}

int main()
{
    int n;
    string s;
    while(cin >> n)
    {
        if(n == 0)break;

        timer = 1;
        dfsroot = 1;
        rchild = 0;

        for(int i = 0; i <= n; i++)
        {
            network[i].clear();
            dfsNum[i] = 0;
            artiVertices[i] = 0;
            parent[i] = 0;
        }
        while(getline(cin, s))
        {
            int u,v;
            if(s == "0")break;
            stringstream ss(s);
            ss >> u;
            while(ss >> v)
            {

                network[u].push_back(v);
                network[v].push_back(u);
            }



        }

        for(int i = 1; i<= n; i++)
        {
            if(!dfsNum[i])
            {
                dfsroot = i;
                rchild = 0;
                dfs(i);
                if(rchild > 1)
                {
                    artiVertices[i] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i<=n; i++)
            if(artiVertices[i])cnt++;

        cout<<cnt<<endl;
    }

    return 0;

}
