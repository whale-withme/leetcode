#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if(doCheck(s))
            return true;

        for(int i = 0, j = s.length()-1; i <= j; i++, j--){
            if(s[i] != s[j]){
                if(!doCheck(s.substr(i, j-i)) && !doCheck(s.substr(i+1, j-i))){
                    return false;
                }else{
                    return true;
                }
            }
        }
        return true;
    }

    bool doCheck(string s){
        for(int i = 0, j = s.length() - 1; i <= j; i++, j--){
            if(s[i] != s[j])
                return false;
        }
        return true;
    }
};