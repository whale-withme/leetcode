/*
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> uset;
        ListNode* index = headA;

        while(index != nullptr){
            uset.insert(index);
            index = index->next;
        }

        for(index = headB; index != nullptr; index = index->next){
            if(uset.find(index) != uset.end()){
                return index;
            }
            else
                continue;
        }

        return NULL;
    }
};