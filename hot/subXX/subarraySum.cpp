/*

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        vector<int> sum;
        sum.push_back(0);
        for(int i = 1; i <= nums.size(); i++){
            //sum[i] = nums[i-1] + sum[i-1];
            sum.push_back(nums[i-1] + sum[i-1]);
        }

        for(int i = 1; i <= nums.size(); i++){
            for(int j = i; j<= nums.size(); j++){
                int m = sum[j] - sum[i-1];

                if(m == k)
                    cnt++;
            }
        }
        return cnt;
    }
};
/** Offical solution:
 * class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};
 */

int main(){
    Solution so;
    vector<int> s = {1,1,1};
    cout << so.subarraySum(s, 2);
}