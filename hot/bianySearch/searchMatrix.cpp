#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int index = 0;
       for(int i = 0; i < matrix.size(); i++){
            int size = matrix[i].size();
            if(matrix[i][size-1] >= target){
                index = i;
                break;
            }
       }

       return binary_search(matrix[index].begin(), matrix[index].end(), target);
    }
};