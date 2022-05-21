//UVa 11686 - Pick up sticks (toposort + cycle check)
#include<bits/stdc++.h>
using namespace std;
int indegree[1000000 + 1];
vector<int>graph[1000000+ 1];

int main()
{
    int node,edge;
    while(scanf("%d %d",&node, &edge) && (node || edge))
    {

        memset(indegree,0,sizeof(indegree));

        for(int i = 0; i<edge; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int>pq;
        for(int i = 1; i<= node; i++)
        {
            if(indegree[i] == 0)
            {
                pq.push(i);
                //cout<<i<<endl;
            }
        }
        vector<int>top_order;
        while(!pq.empty())
        {
            int u = pq.front();//pq.top();
            pq.pop();
            top_order.push_back(u);
            for(auto v: graph[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)pq.push(v);
            }
        }

        if(node != top_order.size())
            printf("IMPOSSIBLE");
        else
            for(int i = 0; i<top_order.size(); i++)
            {
                printf("%d\n",top_order[i]);
            }

        puts("");
        for(int i = 0; i<= node; i++)
            graph[i].clear();
    }


    return 0;

}
