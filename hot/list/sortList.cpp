#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head)
            return head;

        ListNode *p = head, *new_head = nullptr, *q = new_head;
        vector<int> arr;
        while(p){
            arr.push_back(p->val);
            p = p->next;
        }

        sort(arr.begin(), arr.end());
        for(const int tmp : arr){
            ListNode *cnt = new ListNode(tmp);
            if(!new_head)   {new_head = cnt; q = cnt;}
            else{
                q->next = cnt;
                q = q->next;
            }
        }

        return new_head;
    }
};