#include<bits/stdc++.h>
using namespace std;
vector<int>graph[250];
int color[250];
bool visited[250];

bool dfs(int u,int clr)
{

    visited[u] = 1;
    color[u] = clr;
    for(auto v: graph[u])
    {
        if(!visited[v])
        {
            if(dfs(v, clr ^ 1) == false)
                return false;
        }
        else if(u != v && color[v] == color[u])
        {
            return false;
        }
    }
    return true;

}

int main(){

   int node,edge;
   while(scanf("%d",&node) == 1){
       if(node == 0)break;
       scanf("%d",&edge);

       memset(visited,0,sizeof visited);

       for(int i = 1; i <= edge; i++)
       {
           int u, v;
           scanf("%d %d", &u, &v);
           graph[u].push_back(v);
           graph[u].push_back(u);

       }

       if(dfs(0,0)){
            puts("BICOLORABLE.");
        }
        else{
            puts("NOT BICOLORABLE.");
        }

       for(int i = 0; i<= node; i++)
            graph[i].clear();

       memset(color,0,sizeof color);

   }

   return 0;
}
