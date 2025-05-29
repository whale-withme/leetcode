/*
给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
例如，字符串 "ababcc" 能够被分为 ["abab", "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。
注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。

返回一个表示每个字符串片段的长度的列表。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        vector<int> ans;
        int len = s.length();
        vector<int> farthest(len, 0);
        
        for(int i = len-1; i >= 0; i--){
            if(map.find(s[i]) == map.end())
                map[s[i]] = i;
            farthest[i] = map[s[i]];
        }

        int end = 0, start = 0;
        for(int i = 0; i < len; i++){
            end = max(end, farthest[i]);
            if(i == end){
                ans.emplace_back(end-start+1);
                start = i+1;
            }
                
        }

        return ans;
    }
};