#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = 0;
        do{
            slow = nums[slow];
            fast = nums[fast];
        }while(slow != fast);

        return slow;
    }
};