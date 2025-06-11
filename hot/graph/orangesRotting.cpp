#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int freshcount = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rote;
        int minute = 0;
        bool hasRote = false;

        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    rote.push(make_pair(i, j));
                }else if(grid[i][j] == 1)
                    freshcount ++;
            }
        }
        
        while(!rote.empty()){
            int size = rote.size();
            bool roteed = false;
            while(size--){
                pair<int, int> cur = rote.front();
                rote.pop();
                int x = cur.first, y = cur.second;
                helper(x+1, y, grid, rote, roteed);
                helper(x-1, y, grid, rote, roteed);
                helper(x, y+1, grid, rote, roteed);
                helper(x, y-1, grid, rote, roteed);
            }
            if(roteed)
                minute++;
        }


        return freshcount ? -1 : minute;
    }

    void helper(int x, int y, vector<vector<int>>& grid, queue<pair<int, int>>& q, bool& roteed){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 || grid[x][y] == 2)
            return ;

        grid[x][y] = 2;
        roteed = true;
        freshcount--;
        q.push(make_pair(x, y));
    }
};