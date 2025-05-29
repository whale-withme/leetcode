#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int p1 = size - (k%size) -1;
        rearray(nums.begin(), nums.begin()+p1);
        rearray(nums.begin()+((p1+1)%size), nums.end()-1);
        rearray(nums.begin(), nums.end()-1);

    }

    void rearray(vector<int>::iterator begin, vector<int>::iterator end){
        for(; begin <= end; begin++, end--){
            int tmp = *begin;
            *begin = *end;
            *end = tmp;
        }
    }
};