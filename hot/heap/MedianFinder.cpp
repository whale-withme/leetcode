#include <bits/stdc++.h>
using namespace std;


class MedianFinder {

struct cmp{
    bool operator()(int m, int n){
        return m < n;
    }
};
private:

priority_queue<int, vector<int>, less<int>> minHeap;
priority_queue<int, vector<int>, greater<int>> maxHeap;

public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(minHeap.size() == 0 || num < minHeap.top()){
            minHeap.push(num);
            if(maxHeap.size() + 1 < minHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }else{
            maxHeap.push(num);
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() > maxHeap.size())
            return minHeap.top();
        else{
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
};