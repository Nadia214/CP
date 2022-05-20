#include<bits/stdc++.h>
using namespace std;
int can[26],mp[26][26],used[26];
char str[26];
int has;
void dfs(int idx, int n)
{
    //char  str[26];
    if(idx == n){
        //str[idx] = '\0';
        has = 1;
        putchar(str[0]);
        for(int i = 1; i < n; i++)
            printf(" %c", str[i]);
        puts("");
        return;
    }

    for(int i = 0; i<26; i++){
        if(can[i] == 1 && used[i] == 0){
            for(int j = 0; j<26; j++){
                if(mp[i][j] == 1 && used[j] ==1)return;
            }

            used[i] = 1;
            str[idx] = i + 'A';
            dfs(idx + 1, n);
            used[i] = 0;
        }
    }
}

int main(){

    char ch1, ch2, ch3;
    int first = 0;
    stringstream sin;
    string line;
    int cs;
    cin>>cs;
    //getchar();
    while(cs--)
    {
        getchar();
        getline(cin, line);
        if(first)puts("");
        first = 1;

        memset(can, 0, sizeof(can));
        memset(used, 0, sizeof(used));
        memset(mp, 0, sizeof(mp));
        sin.clear();
        sin << line;
        int n = 0;
        while(sin >> ch1){
            can[ch1 - 'A'] = 1;
            n++;
        }
        sin.clear();
        getline(cin, line);
        sin << line;
        while(sin >> ch1 >> ch2 >> ch3){
            mp[ch1 - 'A'][ch3 - 'A'] = 1;

        }
        has = 0;
        dfs(0,n);

        if(!has)
            puts("NO");
        if(cs)
            puts("");
    }



    return 0;
}
