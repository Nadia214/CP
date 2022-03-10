#include<bits/stdc++.h>
using namespace std;


vector<int>graph[1010];
bool visited[1010];
int colour[1010];
int city[1010];



void BFS(int src)
{

    queue<int>q;
    q.push(src);

    while(!q.empty())
    {

        int u = q.front();
        q.pop();

        for(int adj : graph[u])
        {
            if(!visited[adj])
            {
                visited[adj] = 1;
                colour[adj] +=1;
                q.push(adj);
            }
        }

    }

    return;


}

int main()
{

    int T,cs = 1;
    cin>>T;
    while(T--)
    {

        int no_ppl,no_city,con;
        cin>>no_ppl>>no_city>>con;





        memset(city,0,sizeof(city));
        for(int i = 0; i<=no_city; i++)
        {
            graph[i].clear();
        }


        for(int i = 1; i<= no_ppl; i++)
        {
            cin>>city[i];
        }

        for(int i = 1; i<=con ; i++ )
        {
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
        }


        int ans = 0;
        memset(colour ,0 , sizeof(colour));
        for(int i = 1; i<=no_ppl; i++)
        {

            memset(visited,0,sizeof(visited));
            visited[city[i]] = 1;
            colour[city[i]]++;
            BFS(city[i]);


        }

        for(int i = 1; i<= no_city; i++)
        {
            if(colour[i] == no_ppl)
            {
                ans++;
            }
        }


        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }




    return 0;
}
