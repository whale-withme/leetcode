#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;                                // 节点上存储的元素
    ListNode *next;                         // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {} // 节点的构造函数
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(head == nullptr || head->next == nullptr)
            return head;
            
        ListNode *pre = head, *cur = head->next;
        pre->next = nullptr;
        while(cur != nullptr){
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};