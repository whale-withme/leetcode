#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int max(int a, int b, int c) {
        return std::max(a, std::max(b, c));
    }
    int min(int a, int b, int c) {
        return std::min(a, std::min(b, c));
    }

    // 用一个整数值存也可以，不用向量，需要考虑0
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int res = nums[0];
        vector<int> max_positive(size), max_nagtive(size);
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                max_positive[i] = nums[0];
                max_nagtive[i] = nums[0];        
            }
            else{
                max_positive[i] = max(max_positive[i-1] * nums[i], max_nagtive[i-1] * nums[i], nums[i]);
                max_nagtive[i] = min(max_positive[i-1] * nums[i], max_nagtive[i-1] * nums[i], nums[i]);
                res = std::max(max_positive[i], res);
            }
        }

        return res;
    }
};