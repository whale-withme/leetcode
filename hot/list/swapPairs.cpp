/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)    return head; 
        ListNode *before = new ListNode(0);
        before->next = head;

        ListNode *tmp = before, *p = head, *q = head->next;
        while(p && q){
            tmp->next = q;
            p->next = q->next;
            q->next = p;

            tmp = p;
            p = p->next;
            if(p == nullptr)
                break;
            q = p->next;
        }

        return before->next;
    }
};