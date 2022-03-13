#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pair<int,int>>graph[110];
int dist[110];
bool visited[110];
int junction,con;

int dijkstra(int src, int des)
{

    for(int i = 0; i<110; i++)
    {
        dist[i] = INT_MAX;
    }


    memset(visited,0,sizeof(visited));

    priority_queue<pi, vector<pi>, greater<pi> > pq;
    pq.push({0,src});

    dist[src] = 0;

    while(!pq.empty())
    {
        pi u = pq.top();
        int current_node = u.second;
        int current_dist = u.first;

        pq.pop();
        if(current_node == des)break;
        visited[current_node] = 1;
        for(pi adj : graph[current_node])
        {
            if(dist[current_node] + adj.second <dist[adj.first] && !visited[adj.first] )
            {

                dist[adj.first] = current_dist + adj.second;
                pq.push({dist[adj.first],adj.first});

            }
        }
    }

    return dist[des];


}

int main()
{

    int T,cs = 1;
    cin>>T;

    while(T--)
    {
        cin>>junction>>con;

        //clearing vector
        for(int i = 0; i<junction ; i++)
        {
            graph[i].clear();
        }

        for(int i = 0; i<con; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        int ans = dijkstra(1,junction);

        if(ans == INT_MAX)
            cout<<"Case "<<cs++<<": "<<"Impossible"<<endl;
        else
            cout<<"Case "<<cs++<<": "<<ans<<endl;



    }



    return 0;
}
