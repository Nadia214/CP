#include<bits/stdc++.h>
using namespace std;


struct edge
{

    int from,to,cost;


    bool operator <(const edge &p)const
    {

        return cost<p.cost;

    }


};

vector<edge>graph;
int rank_a[505];
int parent[505];
int dist[505];

int city,road,home;


void make_parent(int node)
{
    parent[node]=node;
    rank_a[node]=0;
    return;
}

int find_parent(int node)
{
    if(node!=parent[node]) return parent[node]=find_parent(parent[node]);
    return parent[node];
}


void join(int a,int b)
{
    if(rank_a[a]>rank_a[b]) parent[b]= a;
    else
    {
        parent[a]= b;
        if(rank_a[a]==rank_a[b]) rank_a[b]++;
    }
    return;
}


void mst()
{

    //make parent
    for(int i = 0; i<city ; i++)
    {
        make_parent(i);


    }

    for(int i = 0; i<graph.size(); i++)
    {
        int from = graph[i].from;
        int to = graph[i].to;
        int cost  = graph[i].cost;


        if(find_parent(from) != find_parent(to))
        {
            join(find_parent(from),find_parent(to));
            for(int i = 0; i<city ; i++)
            {

                if(find_parent(i) == find_parent(home) && dist[i] == -1)
                {
                    dist[i] = cost;
                }

            }


        }
    }




}


int main()
{
    int T,cs =1;
    scanf(" %d",&T);

    while(T--)
    {
        graph.clear();
        scanf(" %d %d",&city,&road);



        for(int i = 0; i<road; i++)
        {
            int u,v,w;
            scanf(" %d %d %d",&u,&v,&w);
            edge tmp;
            tmp.from= u;
            tmp.to  = v;
            tmp.cost = w;
            graph.push_back(tmp);
        }


        scanf(" %d",&home);
        memset(dist,-1,sizeof dist);
        sort(graph.begin(),graph.end());
        mst();
        cout<<"home : "<<dist[home]<<endl;
        dist[home] = 0;

        printf("Case %d:\n",cs++);

        for(int i = 0 ; i<city; i++)
        {
            if(dist[i] != -1)

            {

                printf("%d\n",dist[i]);

            }
            else
                printf("Impossible\n");
        }


    }





    return 0;
}
