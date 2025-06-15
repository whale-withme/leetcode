#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    unordered_set<int> colMark, masterMark, secondMark;
    vector<vector<string>> ans;

    bool check(int i, int j){
        if(colMark.find(j) != colMark.end() || masterMark.find(i-j) != masterMark.end() || secondMark.find(i+j) != secondMark.end())
            return false;
        else
            return true;
    }
public:
    int N = -1;
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(N, string(N, '.'));
        dfs(0, board);
        return ans;
    }

    void dfs(int row, vector<string>& board){
        if(row == N){ 
            ans.push_back(board);
            return ;
        }

        for(int j = 0; j < N; j++){
            if(check(row, j)){
                board[row][j] = 'Q';
                colMark.insert(j), masterMark.insert(row-j), secondMark.insert(row+j);
                dfs(row+1, board);
                colMark.erase(j), masterMark.erase(row-j), secondMark.erase(row+j);
                board[row][j] = '.';
            }
        }
    }
};