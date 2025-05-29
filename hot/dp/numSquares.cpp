#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> arr(n+1);
        arr[0] = 0;
        for(int i = 1; i <= n; i++){
            int cnt = INT_MAX;

            for(int j = 1; j*j <= i; j++){
                cnt = min(arr[i-j*j]+1, cnt);
            }
            arr[i] = cnt;
        }

        return arr[n];
    }
};