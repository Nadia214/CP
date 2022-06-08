#include<bits/stdc++.h>
using namespace std;
vector<int> graph[120];
bool visited[120];
int cnt;
void bfs(int src)
{
    memset(visited, 0, sizeof visited);
    queue<int > q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto v : graph[node])
        {
            if(visited[v]) continue;
            if(!visited[v])
            {
                visited[v] = 1;
                cnt++;
                q.push(v);
            }
        }
    }
}
int main()
{

    int vertices;//node
    while(cin >> vertices, vertices)
    {

        int x, y;
        while(cin >> x, x)
        {
            while(cin >> y,y)
            {
                graph[x].push_back(y);
            }
        }

        int m,a;
        cin >> m;

        for(int i = 0; i < m; i++)
        {
            cin >> a;
            cnt = 0;
            bfs(a);
            cout<<vertices - cnt;
            for(int i = 1; i <= vertices; i++)
            {

                if(!visited[i])
                {
                    cout << ' ' << i;
                }

            }
            cout<< '\n';
        }


        for(int i = 0; i <= vertices; i++)
        {
            graph[i].clear();
        }

    }
    return 0;

}
