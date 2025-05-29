#include<bits/stdc++.h>
using namespace std;

/**
 * 思路：把 String 转换成字符串数组，然后排序，这样打乱的字符串就是一样的。
 * 排序好的字符串存到哈希表中，排序后的字符串作为 key，出事的作为value加入到vector中
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        
        for(string& str : strs){
            string key = str;
            sort(key.begin(), key.end());   // 作为同组的标志

            map[key].emplace_back(str);
        }

        for(auto it = map.begin(); it != map.end(); it++){
            ans.push_back(it->second);
        }

        return ans;
    }
};