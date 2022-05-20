#include<bits/stdc++.h>
using namespace std;
int can[26],mp[26][26],used[26];
char str[26];
void dfs(int idx, int n)
{

    if(idx == n){
        str[idx] = '\0';
        puts(str);
        return;
    }

    for(int i = 0; i<26; i++){
        if(can[i] == 1 && used[i] == 0){
            for(int j = 0; j<26; j++){
                if(mp[i][j] == 1 && used[j] ==1)return;
            }

            used[i] = 1;
            str[idx] = i + 'a';
            dfs(idx + 1, n);
            used[i] = 0;
        }
    }
}

int main(){

    char ch1, ch2;
    int first = 0;
    stringstream sin;
    string line;


    while(getline(cin, line))
    {
        if(first)puts("");
        first = 1;

        memset(can, 0, sizeof(can));
        memset(used, 0, sizeof(used));
        memset(mp, 0, sizeof(mp));
        sin.clear();
        sin << line;
        int n = 0;
        while(sin >> ch1){
            can[ch1 - 'a'] = 1;
            n++;
        }
        sin.clear();
        getline(cin, line);
        sin << line;
        while(sin >> ch1 >> ch2){
            mp[ch1 - 'a'][ch2 - 'a'] = 1;
        }
        dfs(0,n);
    }



    return 0;
}
