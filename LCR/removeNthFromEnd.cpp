#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            count++;
        }

        if(n == count)
            return head->next;

        ListNode* pre = head, *current = head->next;
        int step = 0;
        while(current != nullptr && step < count-n){
            current = current->next;
            pre = pre->next;
            step++;
        }

        pre->next = current->next;
        current->next = nullptr;
        return head;
    }
};