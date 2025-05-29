/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();

        for(int i = 0; i < len; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                // 要先判断是不是空stack
                if(st.empty())
                    return false;
                char top = st.top();
                if(s[i] == ')' && top != '(')
                    return false;
                else if(s[i] == '}' && top != '{')
                    return false;
                else if(s[i] == ']' && top != '[')
                    return false;
                st.pop();
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};