/*
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，
并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。
输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> bigger;
        unordered_map<int, int> map;

        for(int i = 0; i < nums2.size(); i++){
            int tmp = nums2[i];
            if(bigger.empty())
                bigger.push(tmp);
            else{
                while(!bigger.empty() && bigger.top() < tmp){
                    map[bigger.top()] = tmp;
                    bigger.pop();
                }
                bigger.push(tmp);
            }
        }

        for(int i = 0; i < nums1.size(); i++){
            if(map.find(nums1[i]) != map.end())
                ans.push_back(map[nums1[i]]);
            else{
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
