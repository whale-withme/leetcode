#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool ans = false;
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    backtrack(board, word, i, j, 0);
                    if(ans)
                        break;
                }
            }
        } 
        return ans;
    }

    void backtrack(vector<vector<char>>& board, string word, int x, int y, int index){
        if(ans) return;
        if(x >= board.size() || y >= board[0].size() || x < 0 || y < 0 || board[x][y] != word[index])
            return ;
        else if(index == word.size()-1 && board[x][y] == word[index]){
            ans = true;
            return ;
        }else{
            char tmp = board[x][y];
            board[x][y] = '#';
            backtrack(board, word, x+1, y, index+1);
            backtrack(board, word, x, y+1, index+1);
            backtrack(board, word, x-1, y, index+1);
            backtrack(board, word, x, y-1, index+1);
            board[x][y] = tmp;
        }
    }
};