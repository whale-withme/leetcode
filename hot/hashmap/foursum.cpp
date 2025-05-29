/*
给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> umap;
        int cnt = 0;
        for(int n : nums3)
            for(int m : nums4){
                umap[n+m]++;
            }

        for(int i : nums1)
            for(int j : nums2){
                if(umap.find(0-i-j) != umap.end())
                    cnt += umap[0-i-j];
            }
        
        return cnt;
        // unordered_map<int, int> map;
        // int ans = 0;
        // for(int i = 0; i < nums4.size(); i++)
        //     map[nums4[i]]++;

        // for(int i = 0; i < nums1.size(); i++)
        //     for(int j = 0; j < nums2.size(); j++)
        //         for(int m = 0; m < nums3.size(); m++){
        //             if(map.find(0-nums1[i]-nums2[j]-nums3[m]) != map.end())
        //                 ans += map[0-nums1[i]-nums2[j]-nums3[m]];
        //         }
        
        // return ans;

        // int ans = 0;
        // sort(nums3.begin(), nums3.end());
        // sort(nums4.begin(), nums4.end());

        // for(int i = 0; i < nums1.size(); i++){
        //     for(int j = 0; j < nums2.size(); j++){
        //         int l = 0, r = nums4.size()-1;
        //         while(l < nums3.size() && r >=0){
        //             if(nums1[i] + nums2[j] + nums3[l] + nums4[r] == 0){
        //                 int ld = 1, rd = 1;
        //                 while(l <nums3.size()-1 && nums3[l] == nums3[l+1] ){
        //                     ld++;
        //                     l++;
        //                 }
        //                 while(r > 0 && nums4[r] == nums4[r-1]){
        //                     rd++;
        //                     r--;

        //                 } 
        //                 ans += ld*rd;
        //                 l++, r--;
        //                 // while(nums1[i] + nums2[j] + nums3[l] + nums4[r] == 0 && l < nums3.size() && r >=0){
        //                 //     int tmp = r;
        //                 //     while(nums1[i] + nums2[j] + nums3[l] + nums4[tmp] == 0 && l < nums3.size() && tmp >=0){
        //                 //         tmp--;
        //                 //         ans++;
        //                 //     }
        //                 //     l++;
        //                 // }
        //             }
        //             else if(nums1[i] + nums2[j] + nums3[l] + nums4[r] > 0)
        //                 r--;
        //             else if(nums1[i] + nums2[j] + nums3[l] + nums4[r] < 0)
        //                 l++;
        //         }
        //     }
        // }

        // return ans;
    }
};

int main (){
    Solution so;
    vector<int> n1 = {1,2}, n2 = {-2, -1}, n3 = {-1, 2}, n4 = {0, 2};
    cout << so.fourSumCount(n1, n2, n3, n4);
}