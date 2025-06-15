#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        for(int i = 0; i < height.size(); i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int bottom = st.top();
                st.pop();
                if(st.empty())
                    break;
                int left = st.top();
                ans += (min(height[i], height[left]) - height[bottom]) * (i - left - 1);
            }
            st.push(i);
        }
        return ans;
    }
};