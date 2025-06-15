#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int divide(int m, int n) {
        if(m == INT_MIN && n == -1)
            return INT_MAX;
        long ans = 0;
        long a = labs(m), b = labs(n);

        while(a >= b){
           long n = 1, base = b;
           while((base << 1) <= a){
                base <<= 1;
                n <<= 1;
           }

           a -= base;
           ans += n;
        }
        
        return (m > 0) ^ (n > 0) ? -ans : ans;
    }
};