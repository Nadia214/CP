#include<bits/stdc++.h>
using namespace std;
#define MOD 100000007

int n, K, dp[51][1010],value[51], quantity[51];

int f(int pos, int rem)
{
    if(rem == 0) return pos <= n;
    if(rem < 0 || pos >= n)return 0;
    if(dp[pos][rem] != -1) return dp[pos][rem];
    int res = 0;
    for(int i = 0; i <= quantity[pos]; i++)
    {
        res = (res + f(pos + 1, rem - (i* value[pos]))) % MOD;
    }

    return dp[pos][rem] = res ;
}

int main()
{
    int T, cs = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d", &n,&K);

        for(int i = 0; i < n; i++)
            scanf("%d",&value[i]);

        for(int i = 0; i < n; i++)
            scanf("%d",&quantity[i]);

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= K; j++)
                dp[i][j] = -1;

        printf("Case %d: %d\n", cs++, f(0,K));
    }
    return 0;
}
