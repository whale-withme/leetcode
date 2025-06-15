#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
       stack<int> numStack;
       stack<string> stringStack;
       
       string currentString;
       int n;

       for(auto ch : s){
            if(ch >= '1' && ch <= '9'){
                n = n*10 + ch - '0';
            }else if (ch >= 'a' && ch <= 'z'){
                currentString += ch;
            }else if(ch == '['){
                numStack.push(n);
                stringStack.push(currentString);
                currentString.clear();
                n = 0;
            }else if(ch == ']'){
                int times = numStack.top();
                string loop = "";
                while(times--){
                    loop += currentString;
                }
                currentString = stringStack.top() + loop;
                stringStack.pop();
                numStack.pop();
            }

       }
       return currentString;
    }
};