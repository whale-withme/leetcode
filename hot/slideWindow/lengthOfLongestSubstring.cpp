/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int l = 0, r = 0;
            int maxw = 0;
            unordered_map<char, int> map;
           
            while(r < s.length()){
                if(map.find(s[r]) != map.end() && map[s[r]] >= l){  // 保证L只会向前移动
                    l = map[s[r]] + 1;
                }

                map[s[r]] = r;
                maxw = max(maxw, r-l+1);
                r++;
            }
            return maxw;
        }
};

int main(){
    Solution so;
    cout << so.lengthOfLongestSubstring("abcabcbb");
}