#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), l = 0, r = 0;
        int mid = (m + n) / 2, count = 0, ans = -1;

        while(count++ <= mid){
            if(l < m && (r >= n || nums1[l] < nums2[r])){
                ans = nums1[l];
                l++;
            }else{
                ans = nums2[r];
                r++;
            }
        }

        if((m+n) % 2){
            int min_ = min(nums1[l], nums2[r]);
            return double((ans + min_) / 2);
        }else{
            return double(ans);
        }
    }
};