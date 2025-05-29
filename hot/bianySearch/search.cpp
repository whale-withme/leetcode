#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }

        int mid = -1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1]){
                mid = i -1;
                break;
            }
        }

        if(mid != -1){
            int l = helper(nums, 0, mid, target), r = helper(nums, mid+1, nums.size()-1, target);
            if(l == -1) return r;
            else return l;
        }else{
            return helper(nums, 0, nums.size()-1, target);
        }
    }
    int helper(vector<int> &arr, int start, int end, int target){
        if(end - start == 1){
            if(target == arr[start])    return start;
            else if(target == arr[end]) return end;
            else    return -1;
        }
        else if(start == end){
           if(arr[start] == target) return start;
           else return -1; 
        }

        int mid = (start + end) / 2;
        if(target < arr[mid])
            return helper(arr, start, mid, target);
        else if(arr[mid] < target)
            return helper(arr, mid+1, end, target);
        else
            return mid;
    }
};