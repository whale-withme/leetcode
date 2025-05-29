// 呈最多水的容器
/**

给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
 */
#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maxArea(vector<int>& height) {
            priority_queue<int> maxheap;
            int len = height.size();
            int lm = 0, rm = 0;

            for(int i = 0; i < len; i++){
                if(height[i] < lm)
                    continue;

                lm = height[i];
                rm = 0;
                for(int j = len-1; j > i; j--){
                    if(height[j] >= rm){
                        rm  = height[j];
                        int area = (j - i) * min(height[i], height[j]);
                        maxheap.push(area);
                    }
                    else
                        continue;
                }
            }

            return maxheap.top();
        }
};

class Solution1 {
    public:
        int maxArea(vector<int>& height) {
            int l = 0, r = height.size() - 1;
            int maxarea = 0;
            
            while(l <= r){
                int cur = (r - l) * min(height[l], height[r]);
                if(cur >= maxarea)
                    maxarea = cur;

                height[l] >= height[r] ? r-- : l++;     // 关键：选择某一个指针移动
            }

            return maxarea;
        }
    };

int main(){
    Solution so;
    vector<int> test = {1,8,6,2,5,4,8,3,7};
    cout << so.maxArea(test);
}