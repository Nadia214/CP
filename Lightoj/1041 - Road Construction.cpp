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
map<string,int>mp;
int roads;


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


int mst(int n)
{
    int ans = 0;

    //make parent
    for(int i = 1; i<=n ; i++)
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
            ans += cost;



        }
    }

    for(int i = 1; i<n; i++)
    {
        for(int j = 1; j<n; j++)
        {
            if(find_parent(i) != find_parent(j))
                return -1;
        }
    }

    int par= find_parent(1);
    for(int i=2; i<=n; i++)
    {
        if(find_parent(i)!=par)
            return -1;
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
        mp.clear();
        memset(rank_a,0, sizeof rank_a);
        memset(parent,0,sizeof parent);

        scanf(" %d",&roads);

        int node_no = 1;

        int value;
        for(int i = 0; i<roads; i++)
        {

            string str1,str2;
            int w;
            cin >> str1 >> str2;
            scanf(" %d",&w);
            if(mp[str1] == 0)
            {

                mp[str1] = node_no;
                node_no++;
            }
            if(mp[str2] == 0)
            {

                mp[str2] = node_no;
                node_no++;
            }


            /*if(mp.find(str1) == mp.end()){
            }*/
            edge tmp;
            tmp.from= mp[str1];
            tmp.to  = mp[str2];
            tmp.cost = w;
            graph.push_back(tmp);

        }




        sort(graph.begin(),graph.end());
        int minimum_cost = 0;
        minimum_cost = mst(mp.size());



        if(minimum_cost == -1)

        {

            printf("Case %d: Impossible\n",cs++);


        }
        else
            printf("Case %d: %d\n",cs++,minimum_cost);




    }





    return 0;
}
