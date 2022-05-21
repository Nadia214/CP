#include<bits/stdc++.h>
using namespace std;

vector<int> graph[105];
vector<int>result;
int dis[105];
bool vis[105];

int n,m;
void dfs(int u){

   vis[u] = 1;
  // cout<<"current node"<<u<<endl;
   for(auto v:graph[u])
   {
       if(!vis[v]){
        dfs(v);
       }
   }
   result.push_back(u);

}


void topsort(){

   memset(vis,0,sizeof(vis));
   result.clear();

   for(int i= 1;i<=n;i++)
    {
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(result.begin(),result.end());
}

int main(){

     //int n,m;
     while(scanf("%d %d", &n, &m) && (n||m)){
      //  if(n==0 && m==0)break;


         for(int i=1; i<=m;i++){
           int u,v;
           cin>>u>>v;
           graph[u].push_back(v);
        }
         topsort();

         for(int i=0;i<result.size();i++){
            if(i==result.size()-1){
                cout<<result[i]<<"\n";

            }
            else
                cout<<result[i]<<" ";
         }


     }




  return 0;
}
