/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> &m, pair<int, int> &n){
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        // 这个堆的定义是难点，比较函数以及 pair
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> heap(cmp);
        unordered_map<int, int> map;

        for(int &tmp: nums)
            map[tmp]++;

        for(auto &[value, freq] : map){
            if(heap.size() == k){
                int k = heap.top().second;
                if(freq >= k){
                    heap.pop();
                    heap.emplace(value, freq);  //省去了构造函数，或者用push && make_pair直接构造
                }
            }
            else{
                heap.emplace(value, freq);
            }
        }

        while(!heap.empty()){
            ans.emplace_back(heap.top().first);
            heap.pop();
        }
        return ans;
    }
};