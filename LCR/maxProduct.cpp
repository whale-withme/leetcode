#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     unordered_set<char> set;

//     bool crossString(string a, string b){
//         bool flag = false;
//         for(char ch: a)
//             set.insert(ch);
        
//         for(char target: b){
//             if(set.find(target) != set.end()){
//                 flag = true;
//                 break;
//             }
//         }
//         set.clear();
//         return flag;
//     }

//     int maxProduct(vector<string>& words) {
//         int maxlen = -1;
//         for(int i = 0; i < words.size(); i++){
//             for(int j = i+1; j < words.size(); j++){
//                 if(!crossString(words[i], words[j]))
//                     maxlen = max(maxlen, (int)(words[i].length() * words[j].length()));
//             }
//         }

//         return maxlen == -1 ? 0 : maxlen;
//     }
// };
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        int maxlen = 0;

        for(int i = 0; i < n; i++){
            for(char ch: words[i]){
                mask[i] |= (1 << ch - 'a');
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(!(mask[i] & mask[j]))
                    maxlen = max(maxlen, (int)(words[i].length() * words[j].length()));
            }
        }

        return maxlen;
    }
};