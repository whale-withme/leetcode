#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        
        int n = num1.size(), m = num2.size();
        vector<int> multi(n + m);
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int nbit = i >= 0 ? num1[i] - '0' : 0;
                int mbit = j >= 0 ? num2[j] - '0' : 0;

                multi[n - 1 - i + m - 1 - j] += nbit * mbit;
            } 
        }

        for(int i = 0; i < multi.size()-1; i++){
            multi[i+1] += multi[i] / 10;
            multi[i] = multi[i] % 10;
        }

        int index = multi.size();
        while(index > 0){
            if(multi[index-1] == 0){
                multi.pop_back();
                index--;
            }else{
                break;
            }
        }

        reverse(multi.begin(), multi.end());
        string ans;
        for(int i = 0; i < multi.size(); i++){
            ans.push_back(multi[i] + '0');
        }

        return ans;
    }
};