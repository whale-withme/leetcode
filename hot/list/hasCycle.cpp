/*
给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head, *slow = head;

        // fast 指针移动到链表的末尾，其实开头容错可以，如果有环的话最后一定会相遇
        while(fast != NULL && fast->next != NULL){
            // if(slow != head && fast != head && slow == fast)
            //     return true;
            
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast)
                return true;
        }
        return false;
    }
};