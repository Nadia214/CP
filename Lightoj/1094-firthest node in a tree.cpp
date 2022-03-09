#include<bits/stdc++.h>
using namespace std;

vector<int>graph[30010];
vector<int>cost[30010];
int dist[30010];

int n;

void BFS(int src)
{

    for(int i = 0; i<n; i++)
    {
        dist[i] = INT_MAX/2;
    }

    queue<int>q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i<graph[u].size(); i++)
        {
            int adj = graph[u][i];
            if(dist[adj]>dist[u]+cost[u][i])
            {
                dist[adj] = dist[u] + cost[u][i];
                q.push(adj);
            }
        }
    }

    return;



}



int main()
{

    int T,cs=1;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i = 0; i<=n ; i++)
        {
            graph[i].clear();
            cost[i].clear();
            dist[i] =0;
        }

        for(int i = 0; i<n-1; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;

            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        BFS(0);

        int src = 0;
        int max_distance = dist[0];

        for(int i = 0; i<n; i++)
        {
            if(dist[i]>max_distance)
            {
                src = i;
                max_distance = dist[i];
            }
        }
        BFS(src);

        for(int i = 0; i<n-1; i++)
        {
            if(dist[i]>max_distance)
            {

                max_distance = dist[i];

            }
        }

        cout<<"Case "<<cs++<<": "<<max_distance<<endl;
    }




    return 0;
}
