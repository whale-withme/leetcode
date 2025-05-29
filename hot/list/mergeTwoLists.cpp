/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *pa = list1, *pb = list2;
        ListNode *head = NULL, *index = NULL;

        if(list1 == nullptr)
            return list2;
        else if(list2 == nullptr)
            return list1;
            

        while(pa != nullptr && pb != nullptr){
            if(pa->val <= pb->val){
                if(!head){
                    head = pa;
                    index = head;
                }
                else{
                    index->next = pa;
                    index = pa;
                } 
                pa = pa->next;
            }
            else{
                if(!head){
                    head = pb;
                    index = head;
                }
                else{
                    index->next = pb;
                    index = pb;
                }
                pb = pb->next;
            }
        }

        if(pa == nullptr)
            while(pb != nullptr)  { index->next = pb; pb = pb->next; index = index->next; }
        else if(pb == nullptr)
            while(pa != nullptr)  { index->next = pa; pa = pa->next; index = index->next; }
        
        return head;
    }
};