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
    void reorderList(ListNode* head) {
        ListNode *mid = findMiddle(head);
        ListNode *rightReverse = reverseList(mid->next);
        mid->next = nullptr;
        mergeList(head, rightReverse);
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

   ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
   }

   void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};