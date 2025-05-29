#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int tmp: nums)
            set.insert(tmp);

        int cnt = 0, ans = 0;
        for(auto it = set.begin(); it != set.end(); ){
            if(!set.count((*it)-1)){
                cnt = 1;
                ans = max(ans, cnt);
            }
            else{
                while(set.count((*it)-1)){
                    it = set.erase(it);
                    cnt++;
                    ans = max(ans, cnt);
                }              
            }
        }

        return ans;
    }          
};