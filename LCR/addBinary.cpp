#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length(), lb = b.length();
        int i = la-1, j = lb-1, carry = 0;
        string ans;
        
        while(i >= 0 || j >= 0 || carry){
            int adda = (i >= 0) ? a[i--]-'0' : 0;
            int addb = (j >= 0) ? b[j--]-'0' : 0;

            int sum = adda + addb + carry;
            ans.push_back((char)(sum % 2 + '0'));
            carry = sum / 2;

        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};