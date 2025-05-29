/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = nullptr;
        int sum = 0, flag = 0, cnt = 0;

        while(p){ sum++; p = p->next;}
        flag = sum - n;
        if(!flag)   return head->next;

        p = head;
        while(cnt != flag){
            q = p;
            p = p->next;
            cnt++;
        }

        q->next = p->next;
        p->next = nullptr;
        return head;
    }
};