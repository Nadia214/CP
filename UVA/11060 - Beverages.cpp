#include<bits/stdc++.h>
using namespace std;


int main()
{
    int cs = 1;
    int n;
    while(scanf("%d",&n) != EOF)
    {

        vector<string>beverages(n);
        unordered_map<string,int> mp;
        for(int i =0; i<n; i++)
        {
            cin>>beverages[i];
            mp[beverages[i]] = i;

        }

        int m;
        cin >> m;
        vector<int>graph[n];
        int incoming[100];
        memset(incoming, 0, sizeof(incoming));

        while(m--)
        {
            string a, b;
            cin>>a>>b;
            graph[mp[a]].push_back(mp[b]);
            incoming[mp[b]]++;
        }

        priority_queue<int>q;
        for(int i = 0; i < n; i++)
        {
            if(!incoming[i])
            {
                q.push(-i);

            }
        }
        vector<int>result;

        while(!q.empty())
        {
            int u = -q.top();
            q.pop();
            result.push_back(u);
            for(auto v : graph[u])
            {
                incoming[v]--;
                if(!incoming[v])q.push(-v);

            }

            }

        cout << "Case #" << cs++ << ": Dilbert should drink beverages in this order:";
        for (auto it = result.begin(); it != result.end(); it++) {
            cout << " " << beverages[*it];
        }
        cout << ".\n\n";


    }

    return 0;
}
