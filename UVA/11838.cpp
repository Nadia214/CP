//UVa 11838 - Come and Go * (check if graph is strongly connected)
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[2010];
int dfn[2010];
int low[2010];
int scc[2010];
int timer,cscc;
stack<int>stk;
void tarjan(int u)
{

    dfn[u] = low[u] = timer++;
    stk.push(u);
    for(auto v: graph[u])
    {

        if(!dfn[v])
        {

            tarjan(v);
            low[u] = min(low[u], low[v]);

        }
        else if(!scc[v])
        {

            low[u] = min(low[u],dfn[v]);

        }
    }

    if(dfn[u] == low[u])
    {

        cscc++;
        cout<<cscc<<endl;
        while(true)
        {
            int v = stk.top();
            stk.pop();
            scc[v] = cscc;
            if(u == v)break;
        }

    }

}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) && (n||m))
    {
        int from, to, p;

        timer = 0;
        cscc = 0;
        for(int i = 0; i<= n; i++)
        {
            graph[i].clear();
        }

        while(!stk.empty())stk.pop();
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(scc, 0, sizeof scc);



        for(int i = 1; i<= m; i++)
        {
            scanf("%d %d %d",&from,&to,&p);
            graph[from].push_back(to);
            if(p == 2)
                graph[to].push_back(from);
        }

        for(int i = 1; i <= n; i++)
        {
            if(!dfn[i])
            {
                tarjan(i);
            }
        }

        if(cscc == 1)
            printf("1\n");
        else
            printf("0\n");


    }

    return 0;

}
