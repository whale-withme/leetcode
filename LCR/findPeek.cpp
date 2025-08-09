#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)   return 0;
        else if(size == 2)  return nums[1] > nums[0] ? 1 : 0;
        int ranNum = doRandom(0, nums.size());

        while(true){
            if(ranNum > 0 && ranNum < size-1 && nums[ranNum-1] < nums[ranNum] && nums[ranNum] > nums[ranNum+1]){
                return ranNum;
            }else if(ranNum == 0 || ranNum == size-1){
                ranNum = doRandom(0, size);
            }else if(ranNum < size-1 && nums[ranNum] < nums[ranNum + 1]){
                ranNum = doRandom(ranNum, size);
            }else if(ranNum > 0 && nums[ranNum] > nums[ranNum - 1]){
                ranNum = doRandom(0, ranNum);
            }
        }
    }

    int doRandom(int l, int r){
        return rand() % (r - l) + l;
    }
};