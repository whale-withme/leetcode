/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums);
        while(--k != 0){
            swap(nums[0], nums[nums.size()-1]);
            nums.pop_back();
            topdown(nums, 0, nums.size());
        }
        return nums[0];
    }

    void topdown(vector<int> &arr, int i, int size){
        int l = 2*i+1, r = 2*i+2, maxer = i;    // 这里是+1 +2
        if(l < size && arr[l] >= arr[maxer])
            maxer = l;
        if(r < size && arr[r] >= arr[maxer]) // 不是 els if 关系，两个都需要比较
            maxer = r;
        if(maxer == i)
            return ;
        swap(arr[i], arr[maxer]);
        topdown(arr, maxer, size);
    }

    void make_heap(vector<int> &arr){
        int size = arr.size();

        for(int i = size/2 - 1; i >= 0; i--){
            topdown(arr, i, size);
        }

        // for(int &t:arr)
        //     cout << t << " ";
    }

};

int main(){
    Solution so;
    vector<int> nums = {0,1,2,3,4,5,9999};
    so.make_heap(nums);
}