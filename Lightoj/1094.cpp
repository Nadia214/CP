#include<bits/stdc++.h>
using namespace std;

#define INF 10000;
vector<int>graph[30000+10];
vector<int>cost[30000+10];
int dist[30000+10];
bool visited[30010];
int n;

void bfs(int src)
{


    for(int i =0; i<n; i++)
    {
        dist[i] = INF;
    }
    memset(visited,0,sizeof(visited));

    queue<int>q;
    q.push(src);
    dist[src] =0;
    visited[src] = 1;



    while(!q.empty())
    {

        int u = q.front();


        q.pop();

        for(int i =0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];

            if(!visited[v]){
            if(dist[v]>dist[u]+cost[u][i])
            {

                dist[v] = dist[u] + cost[u][i];
                q.push(v);
                visited[v] =1;

            }}
        }
    }









}

int main()
{

    int T,cs =1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i<n-1; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);

            graph[u].push_back(v);
            graph[v].push_back(u);

            cost[u].push_back(w);
            cost[v].push_back(w);
        }

        bfs(0);

        int src = 0,max_distance =dist[0];
        for(int i = 1; i<n; i++)
        {
            if(dist[i]>max_distance)
            {

                src = i;
                max_distance = dist[i];
            }
        }


        bfs(src);


        max_distance =dist[0];

        for(int i = 1; i<n; i++)

        {

            if(dist[i]>max_distance)
            {

                max_distance = dist[i];
            }

        }



        printf("Case %d: %d\n",cs++,max_distance);
        for(int i=0; i<n ; i++)
        {
            graph[i].clear();
            cost[i].clear();
            dist[i] =0;
        }

    }


    return 0;


}

