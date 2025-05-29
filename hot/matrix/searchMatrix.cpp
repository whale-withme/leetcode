#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        bool result = false;
        for(int i = 0; i < m; i++){
            if(target < matrix[i][0])
                break;
            if(target <= matrix[i][n-1]){
                result = binary_search(matrix[i].begin(), matrix[i].end(), target);
                if(result)
                    return result;
            }else{
                continue;
            }
        }
        return result;
    }
};