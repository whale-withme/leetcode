#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> result;
        string path;
        backtrack(map, digits, path, result, 0);
        return result;
    }

    void backtrack(unordered_map<char, string> &map, string &digits, string &path, vector<string> &result, int startIndex){
        if(digits.length() == path.length()){
            if(digits.length() != 0)
                result.push_back(path);
            return;
        }
            
        // for(char c : map[digits[path.length()]]){

        // }
        for(int i = startIndex; i < digits.length(); i++){
            for(char c : map[digits[i]]){
                path.push_back(c);
                backtrack(map, digits, path, result, i+1);
                path.pop_back();
            }
        }
    }
};