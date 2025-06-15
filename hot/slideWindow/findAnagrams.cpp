/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
*/

// 怎么解决窗口重复字符问题?

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return vector<int>();
        vector<int> ans;
        vector<int> window(26), arrp(26);

        for(int i = 0; i < p.length(); i++){
            arrp[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        if(arrp == window)
            ans.push_back(0);

        for(int i = 0; i < s.length() - p.length(); i++){
            window[s[i] - 'a']--;
            window[s[i+p.length()] - 'a']++;

            if(arrp == window)
                ans.push_back(i+1);
        }

        return ans;
    }
};