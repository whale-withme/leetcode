#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, result, path);
        return result;
    }

    bool check_palindrome(string s){
        for(int i = 0, j = s.length()-1; i < j; i++, j--){
            if(s[i] != s[j])    return false;
        }
        return true;
    }

    void backtrack(string s, vector<vector<string>>& result, vector<string>& path){
        // 怎么处理结束呢
        if(s.empty()){
            result.push_back(path);
            return ;
        }

        int len = s.length();
        // 如果substr(s.length)会返回一个空字符串
        for(int i = 1; i <= s.length(); i++){
            if(check_palindrome(s.substr(0, i))){
                path.push_back(s.substr(0, i));
                backtrack(s.substr(i, len-i), result, path);
                path.pop_back();
            }
        }
    }
};