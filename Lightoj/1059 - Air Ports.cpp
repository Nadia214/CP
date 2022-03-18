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
int rank_a[10010];
int parent[10010];

int loc,roads,ans;
set<int>st;


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
    for(int i = 1; i<= loc; i++)
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
        st.clear();
        int air_cost;
        scanf(" %d %d %d",&loc,&roads,&air_cost);


            for(int i = 0; i < roads ; i++){
            int u,v,w;
            scanf(" %d %d %d",&u,&v,&w);
            edge tmp;
            tmp.from= u;
            tmp.to  = v;
            tmp.cost = w;
            if(w<air_cost)
               graph.push_back(tmp);

            }


        //memset(dist,-1,sizeof dist);
        sort(graph.begin(),graph.end());
        int best_con = mst();

        for(int i = 1; i<= loc ; i++){
           st.insert(find_parent(parent[i]));
        }

        int component = st.size();

        printf("Case %d: %d %d\n",cs++, (best_con+ (component * air_cost)), component);






    }





    return 0;
}
