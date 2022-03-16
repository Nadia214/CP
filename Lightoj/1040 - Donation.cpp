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
int n,min_node;


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
     int ans = 0;
     min_node = 0;
    //make parent
    for(int i = 0; i<n ; i++)
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
            //cout<<"from : "<<from<<" to " <<to<<" cost "<<cost<<endl;
            join(find_parent(from),find_parent(to));
            min_node++;
            ans += cost;
           // cout<<"ans : "<<ans<<endl;


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
        scanf(" %d",&n);

        int ans = 0;
        int total_cable = 0;
        int value;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n ; j++)
            {
                int value;
                scanf(" %d",&value);
                total_cable += value;
                edge tmp;
                tmp.from= i;
                tmp.to  = j;
                tmp.cost = value;
                if(value)
                    graph.push_back(tmp);
            }
        }




        sort(graph.begin(),graph.end());
        int minimum = mst();


           // cout<<"total_cable "<<total_cable<<endl;

            if(min_node == (n-1))

            {

                printf("Case %d: %d\n",cs++,total_cable - minimum);


            }
            else
                printf("Case %d: -1\n",cs++);




    }





    return 0;
}
