/*
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，
下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>  tem;
        vector<int> ans(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); i++){
            if(tem.empty())
                tem.push(make_pair(i, temperatures[i]));
            else{
                while(!tem.empty() && tem.top().second < temperatures[i]){
                    ans[tem.top().first] = i - tem.top().first;
                    tem.pop();
                }
                tem.push(make_pair(i, temperatures[i]));
            }
        }
        return ans;
    }
};