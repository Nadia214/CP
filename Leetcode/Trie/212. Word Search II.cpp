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
    vector<int> dir{-1, 0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* currNode, vector<string>& wordsOnBoard)
    {
        char ch = board[r][c];
        if(currNode && currNode -> next[ch - 'a'] == NULL)return;

        currNode = currNode -> next[ch-'a'];
        if(currNode && currNode -> word.size() > 0)
        {
           wordsOnBoard.push_back(currNode -> word);
           currNode ->word.clear();
        }
        board[r][c] = '#';
        for(int i = 0; i<4; i++)
        {
            int X = r + dir[i];
            int Y = c + dir[i+1];

            if(X < 0 || Y < 0 ||  X >= board.size() || Y >= board[0].size() || board[X][Y] == '#')continue;
            dfs(X, Y, board, currNode, wordsOnBoard);
        }
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = generateTrieNode(words);
        vector<string>wordsOnBoard;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j<n; j++){
                dfs(i, j, board, root, wordsOnBoard);
            }
        }
        return wordsOnBoard;
    }
};
