#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;                                // 节点上存储的元素
    ListNode *next;                         // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {} // 节点的构造函数
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(!headA || !headB)    return nullptr;
        unordered_set<ListNode *> set;

        ListNode *node = nullptr;
        for (node = headA; node != nullptr; node = node->next)
        {
            set.insert(node);
        }

        for (node = headB; node != nullptr; node = node->next)
        {
            if (set.find(node) != set.end()){
                return node;
            }
        }
        return nullptr;
    }
};