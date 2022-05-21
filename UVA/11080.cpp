#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10000];
int vis[10000],col[10000];
int black,red;


bool is_bipartile(int node,int colour)
{

    vis[node] = 1;
    col[node] = colour;

    if(col[node]==1)black++;
    if(col[node]==0)red++;

    // cout<<"red"<<red<<" black "<<black<<"\n";
    // cout<<"node : "<<node<<" colour "<<col[node]<<"\n";
    for(int adj : graph[node])
    {


        if(!vis[adj])
        {

          //  colour = colour ^ 1;
            if(is_bipartile(adj,colour ^1)== false)return false;
        }
        else
        {

            if(col[node]== col[adj])
            {

                return false;
            }
        }


    }

    return true;





}

int main()
{

    int T;
    cin>>T;

    while(T--)
    {

        int n,m;
        cin>>n>>m;

        for(int i=0 ; i <n; i++ )
        {
            graph[i].clear();
            vis[i] = 0;
        }
        for(int i=0 ; i <m; i++ )
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int flag = true,total = 0;
        //black =0;red =0;
        for(int i=0 ; i<n; i++)
        {


            if(!vis[i])
            {
                black=0;
                red=0;
                bool result = is_bipartile(i,0);
                if(result == false)
                {

                    flag = false;
                    break;
                }

                total += max(1,min(black,red));

            }
        }
        if(flag==true)
            cout<<total<<endl;
        else
            cout<<"-1"<<endl;


    }




    return 0;

}
