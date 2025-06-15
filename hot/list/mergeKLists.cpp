#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};
struct Compare{
    bool cmp(ListNode* m, ListNode* n ){
        return m->val > n->val;
    }
};

class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, Compare> heap;
       ListNode* head = new ListNode(0), *index = head;
       
        for(auto &node : lists){
            if(node)
                heap.push(node);
        }

        while(!heap.empty()){
            ListNode* curr = heap.top();
            index->next = curr;
            index = index->next;
            
            heap.pop();
            if(curr->next)
                heap.push(curr->next);

        }  
        return head->next;      
    }
};