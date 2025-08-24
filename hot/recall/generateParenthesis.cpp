#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path = "";
        generateHelper(n, n, ans, path);
        return ans;
    }

    void generateHelper(int left, int right, vector<string> &ans, string path){
        if(left == right && left == 0){
            ans.push_back(path);
            return;
        }

        if(left > 0){
            path += '(';
            generateHelper(left-1, right, ans, path);
            path.pop_back();
        }

        if(right > left){
            path += ')';
            generateHelper(left, right-1, ans, path);
            path.pop_back();
        }
    }
};