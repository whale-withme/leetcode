#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr;
        arr.emplace_back(1);
        arr.emplace_back(1);

        for(int i = 2; i <= n; i++){
            arr.emplace_back(arr[i-1] + arr[i-2]);
        }

        return arr[n];
    }
};