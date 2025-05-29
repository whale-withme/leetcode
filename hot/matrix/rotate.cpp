#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        // 转置矩阵
        for(int i = 0; i < m-1; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n/2; j++){
                swap(matrix[i][j], matrix[i][m-j-1]);
            }

        
    }
};