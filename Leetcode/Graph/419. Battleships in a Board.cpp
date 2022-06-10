//419. Battleships in a Board
//TC - O(M.N)
//SC - O(1)
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int battleships = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'X' && (!i || board[i - 1][j] == '.') && (!j || board[i][j-1] == '.'))
                    battleships++;
            }
        }
    return battleships;
    }
};
