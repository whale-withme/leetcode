/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
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
bool isPalindrome(ListNode* head) {
    // 转换成数组来用双指针
    vector<int> num;
    ListNode *id = head;

    while(id != NULL){
        num.push_back(id->val);
        id = id->next;
    }

    for(int i = 0, j = num.size()-1; i < j; i++, j--){  // 注意这里 i < j ;防止奇数情况
        if(num[i] != num[j])
            return false;
    }

    return true;
}
};