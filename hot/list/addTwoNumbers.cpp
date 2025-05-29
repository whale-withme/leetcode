/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pa = l1, *pb = l2, *index = nullptr, *head = nullptr;
        int forward = 0;

        while(pa != nullptr && pb != nullptr){
            // 核心：三数之和作为答案
            int ans = (pa->val + pb->val + forward) % 10;
            forward = ((pa->val + pb->val + forward) / 10) >= 1 ? 1 : 0;
            ListNode *l = new ListNode(ans);
            //forward = ((pa->val + pb->val + forward) / 10) >= 1 ? 1 : 0;

            // 头指针设置
            if(head == nullptr){
                head = l;
                index = head;
            }
            else{
                index->next = l;
                index = index->next;
            }

            pa = pa->next;
            pb = pb->next;
        }

        if(pa == nullptr){
            while(pb != nullptr){
                index->next = new ListNode((forward + pb->val) % 10);
                forward = (forward + pb->val) / 10;
                index = index->next;
                pb = pb->next;
            }
        }
        else if(pb == nullptr){
            while(pa != nullptr){
                index->next = new ListNode((forward + pa->val) % 10);
                forward = (forward + pa->val) / 10;
                index = index->next;
                pa = pa->next;
            }
        }

        if(forward == 1){   //最后可能还有进位
            index->next = new ListNode(forward);
        }

        return head;
    }
};