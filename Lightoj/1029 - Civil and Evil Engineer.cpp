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

bool cmp_1(edge a, edge b)
{

    return a.cost>b.cost;

}

vector<edge>graph;
int rank_a[505];
int parent[505];
int dist[505];

int no_home,ans;


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


int mst()
{

    //make parent
    for(int i = 0; i<=no_home ; i++)
    {
        make_parent(i);


    }
    ans = 0;
    for(int i = 0; i<graph.size(); i++)
    {
        int from = graph[i].from;
        int to = graph[i].to;
        int cost  = graph[i].cost;


        if(find_parent(from) != find_parent(to))
        {
            join(find_parent(from),find_parent(to));
             ans += cost;


        }
    }

    return ans;




}


int main()
{
    int T,cs =1;
    scanf(" %d",&T);

    while(T--)
    {
        graph.clear();
        scanf(" %d",&no_home);


        int u,v,w;
        while(scanf(" %d %d %d",&u,&v,&w)==3)
        {
            //int u,v,w;
            if(u == 0 && v==0 && w==0)break;
            edge tmp;
            tmp.from= u;
            tmp.to  = v;
            tmp.cost = w;
            graph.push_back(tmp);
        }



        memset(dist,-1,sizeof dist);
        sort(graph.begin(),graph.end());
        int best_con = mst();
        //cout<<"home : "<<dist[home]<<endl;
        sort(graph.begin(),graph.end(),cmp_1);
        int worst_con = mst();




            if((best_con+worst_con)%2==0)

            {

                printf("Case %d: %d\n",cs++,(best_con+worst_con)/2);

            }
            else
                printf("Case %d: %d/2\n",cs++,best_con+worst_con);



    }





    return 0;
}

