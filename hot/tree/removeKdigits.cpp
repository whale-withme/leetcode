#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int cnt = 0;

        for(char ch: num){
            while(!st.empty() && cnt < k && ch < st.top()){
                st.pop();
                cnt++;
            }
            st.push(ch);
        }

        while(cnt < k && !st.empty()){
            st.pop();
            cnt++;
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int pos = 0;
        while(ans[pos] == '0' && pos < ans.size()){
            pos++;
        }
        ans = ans.substr(pos, ans.size());
        return ans == "" ? "0" : ans;
    }
};