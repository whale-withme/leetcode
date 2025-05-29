#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> xzero, yzero;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    xzero.insert(i);
                    yzero.insert(j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(xzero.find(i) != xzero.end() || yzero.find(j) != yzero.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main(){
    Solution so;
    vector<vector<int>> test = {{1,1,1},{1,0,1},{1,1,1}};

    so.setZeroes(test);
}