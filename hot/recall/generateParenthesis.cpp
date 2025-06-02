#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        backtrack(n, n, result, path);
        return result;
    }

    void backtrack(int left, int right, vector<string>& result, string path){
        if(left == 0 && right == 0){
            result.push_back(path);
            return ;
        }
           
        if(left > 0)
            backtrack(left-1, right, result, path+'(');
        if(right > left)
            backtrack(left, right-1, result, path+')');
    }
};