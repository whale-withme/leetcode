#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;

        for(int i = 0, j = numbers.size()-1; i < j;){
            int sum = numbers[i] + numbers[j];

            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }else if(sum > target){
                j--;
                continue;
            }else if(sum < target){
                i++;
                continue;
            }
        }

        return ans;
    }
};