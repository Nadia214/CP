//Tc - O(S + Σwords)
//sc - O( Σwords)
class Solution {
public:
    class TrieNode
    {
     public:
        int cnt = 0;
        TrieNode* next[26];
        TrieNode()
        {
            for(int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    TrieNode* generateTrieNode(vector<string>& words)
    {
        TrieNode* root = new TrieNode();
        for(auto &wd : words)
        {
            TrieNode* currNode = root;
            for(auto &c : wd)
            {
                int id = c - 'a';
                if(currNode -> next[id] == NULL){
                    currNode -> next[id] = new TrieNode();
                }
                currNode = currNode -> next[id];
            }
            currNode -> cnt++;
        }
        return root;
    }


    int dfs(string& s, TrieNode* u, int pos)
    {
        if(u == NULL) return 0;

        int ans = u -> cnt;
        if (pos >= s.length())return ans;

        for(int i = 0; i < 26; i++){
          if (u->next[i])
          {
             int index = s.find('a' + i, pos);
             if (index != -1)
                 ans += dfs(s, u->next[i],index+1);
          }
        }
        return ans;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        TrieNode* root = generateTrieNode(words);
        return dfs(s, root, 0);;
    }
};
