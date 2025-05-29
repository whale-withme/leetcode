#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }

    int search(vector<int> &arr, int start, int end, int target){
        if(end - start == 1){
            if(target > arr[start] && target <= arr[end])
                return end;
            else if(target <= arr[start])
                return start;
            else if(target > arr[end])
                return end+1;
        }
        else if(start == end){
            if(target <= arr[start]) return start;
            else return start+1;
        }

        int mid = (start + end) / 2;
        if(target < arr[mid])
            return search(arr, start, mid, target);
        else if(arr[mid] < target)
            return search(arr, mid+1, end, target);
        else
            return mid;
    }
};