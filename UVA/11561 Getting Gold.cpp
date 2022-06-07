#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef vector < pair < int, int > > vip;
typedef pair < int, int > pi;
#define F          first
#define S          second
#define PB         push_back
#define MP         make_pair
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define sz(x)      (int)x.size()
#define en         '\n'
#define sp         ' '
int vis[600];
vip grp[600];
int cnt = 0, mex;

void DFS(int src){
    vis[src] += 1;
    cout<<"DFS theke src : " << src <<endl;
    for(auto &a : grp[src]){
        if(a.second != mex){
                cout<<"a.first: "<<a.first<<" a.second : "<<a.second<<endl;
        continue;
    }
        if(vis[a.first] == 0){
            if(a.second == mex){//cout<<" , "<<a.first<<endl;
                cout<<" valid : a.first: "<<a.first<<" a.second : "<<a.second<<endl;

                cnt++;
                cout<<cnt<<endl;
            }
            DFS(a.first);
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i, n, m, x, y, cc, ans;
    while(1){
        mex = INT_MIN;
        cin >> n >> m;
        if(n == 0 && m == 0)break;
        for(i = 0;i < 600;i++)vis[i] = 0;
        for(i = 0;i < 600;i++)grp[i].clear();
        while(m--){
            cin >> x >> y >> cc;
            grp[x].PB({y,cc});
            grp[y].PB({x,cc});
            mex = max(mex, cc);
        }
        ans = 0;
        for(i = 1;i <= n;i++){
            cnt = 0;
            if(vis[i] == 0){
                vis[i] = -1;
                cout<<"source node :"<<i<<endl;
                DFS(i);
            }
            ans = max(ans, cnt);
        }
        cout << ans << en;
    }
    return 0;
}
