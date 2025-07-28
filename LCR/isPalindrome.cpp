#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length(), diff = 'A' - 'a';
        int left = 0, right = len-1;
        
        while(left < right){
            while(left < right && !check(s[left]))  left++;
            while(left < right && !check(s[right])) right--;


            if(left <= right){
                if(!(tolower(s[left]) == tolower(s[right]))){
                    return false;
                }
                right--;
                left++;
            }
        }

        return true;
    }

    bool check(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
};