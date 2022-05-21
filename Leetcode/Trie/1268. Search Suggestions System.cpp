//1268. Search Suggestions System
//TC- O(m * n + L) - where m average length of products, n = products.length , L = searchWord.length().
// SC- O(m * n + L * m)
class Solution {
public:
    class TrieNode
    {
     public: 
        string word;
        TrieNode* next[26];
        TrieNode(){
            word = "";
            for(int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    TrieNode* generateTrieNode(vector<string>& products)
    {
        TrieNode* root = new TrieNode();
        for(auto &wd : products)
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
            currNode -> word = wd;
        }
        return root;
    }
    void dfs(TrieNode* u, vector<string>& words)
    {
        if(u == NULL || words.size() == 3)return;
        
        if(u -> word.size() > 0 && words.size() < 3){
            words.push_back(u -> word);
        }
        for(int i = 0; i < 26; i++){
            dfs(u -> next[i], words);
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
      TrieNode* root = generateTrieNode(products);  
      vector<vector<string>> suggestions;
      for(auto c : searchWord)
      {
          root = root && root -> next[c - 'a'] ? root -> next[c - 'a'] : NULL;
          vector<string>words;
          dfs(root,words);
          suggestions.push_back(words);
      }  
      return suggestions;
    }
};