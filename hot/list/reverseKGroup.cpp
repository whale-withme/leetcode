#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head || head->next || k == 1)    return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;

        while(true){
            ListNode* tail = pre;
            for(int i = 0; i < k; i++){
                tail = tail->next;
                if(tail == nullptr)
                    return dummy->next;
            }

            ListNode *nextGroup = tail->next;
            ListNode* index = pre->next, *prev = nextGroup;

            while(index != nextGroup){
                ListNode* tmp = index->next;
                index->next = prev;
                prev = index;
                index = tmp;
            }

            ListNode* oldhead = pre->next;
            pre->next = tail;
            pre = oldhead;
        }
        return dummy->next;
    }
};