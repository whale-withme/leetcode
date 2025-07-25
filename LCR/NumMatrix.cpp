#include <bits/stdc++.h>
using namespace std;

class NumMatrix {

private:
    vector<vector<int>> nums;
    vector<vector<int>> prefeix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        nums = vector<vector<int>>(m, vector<int>(n));
        prefeix = vector<vector<int>>(m, vector<int>(n));
        int sum = 0;
        for(int i = 0; i < matrix.size(); i++){
            sum = 0;
            for(int j = 0; j < matrix[i].size(); j++){
                sum += matrix[i][j];
                nums[i][j] = matrix[i][j];
                prefeix[i][j] = i > 0 ? sum + prefeix[i-1][j] : sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = prefeix[row2][col2];
        if(col1 > 0){
            ans -= prefeix[row2][col1-1];
        }

        if(row1 > 0){
            ans -= prefeix[row1-1][col2];
        }

        if(row1 > 0 && col1 > 0){
            ans += prefeix[row1-1][col1-1];
        }

        return ans;
    }
};
