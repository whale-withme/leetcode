#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
       ListNode *fast = head, *slow = head;
       
       while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                slow = head;

                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
       }
       return nullptr;
    }
};