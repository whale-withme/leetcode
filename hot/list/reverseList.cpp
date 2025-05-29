/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

/**
 * 怎么解决后节点和前节点之间的链接？
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};