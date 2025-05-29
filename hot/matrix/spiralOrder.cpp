#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int END = -1000;
    // const int l = 0, r = 1, up = 3, down = 4;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m-1, left = 0, right = n-1;
        vector<int> ans;
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            for(int j = top; j <= bottom; j++){
                ans.push_back(matrix[j][right]);
            }
            right--;

            if(top <= bottom && left <= right){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(top <= bottom && left <= right){
                for(int j = bottom; j >= top; j--){
                    ans.push_back(matrix[j][left]);
                }
            }
                
            left++;
        }
        return ans;

        // const int l = 0, r = 1, up = 3, down = 4;
        // int m = matrix.size(), n = matrix[0].size();
        // vector<int> ans;
        // int dir = r, cnt = 0, x = 0, y = 0;

        // while(cnt < m*n){
        //     switch (dir){
        //     case r:{
        //         for(int j = y; j < matrix[x].size() && matrix[x][j] != END; j++){
        //             ans.push_back(matrix[x][j]);
        //             matrix[x][j] = END;
        //             cnt++;
        //             y = j;
        //         }
        //         dir = down;
        //         break;
        //     }
        //     case down:{
        //         for(int i = x; i < matrix.size() && matrix[i][y] != END; i++){
        //             ans.push_back(matrix[i][y]);
        //             matrix[i][y] = END;
        //             cnt++;
        //             x = i;
        //         }
        //         dir = l;
        //         break;
        //     }
        //     case l:{
        //         for(int j = y; j >= 0 && matrix[x][j] != END; j--){
        //             ans.push_back(matrix[x][j]);
        //             matrix[x][j] = END;
        //             cnt++;
        //             y = j;
        //         }
        //         dir = up;
        //         break;
        //     }
        //     case up:{
        //         for(int i = x; i >= 0 && matrix[i][y] != END; i--){
        //             ans.push_back(matrix[i][y]);
        //             matrix[i][y] = END;
        //             cnt++;
        //             x = i;
        //         }
        //         dir = r;
        //         break;
        //     }
            
        //     default:
        //         break;
        //     }
        // }
        // return ans;
    }   
};