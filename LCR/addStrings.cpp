#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        vector<int> add;
        int index = 0;
        for(int i = num1.size()-1, j = num2.size()-1; i >= 0 || j >= 0; i--, j--){
            int ib = i >= 0 ? num1[i] - '0' : 0;
            int jb = j >= 0 ? num2[j] - '0' : 0;

            add.push_back(ib + jb);
        }

        for(int i = 0; i < add.size(); i++){
            if(i+1 < add.size())
                add[i+1] += add[i] / 10;
            else {
                int carry = add[i] / 10;
                if(carry > 0) add.push_back(carry);
            }
            add[i] %= 10;
        }

        index = add.size()-1;
        while(index >= 0 && add[index] == '0'){
            add.pop_back();
            index--;
        }

        reverse(add.begin(), add.end());
        string ans;
        for(int i = 0; i < add.size(); i++){
            ans.push_back(add[i] + '0');
        }

        return ans;
    }
};