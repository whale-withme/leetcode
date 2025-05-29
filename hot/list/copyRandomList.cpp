

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return head;
        unordered_map<Node*, int> listmap;
        unordered_map<int, Node*> newmap;
        Node *new_head = new Node(head->val), *p = head, *q = new_head;

        int index = 0;
        while(p){
            if(p->next){
                q->next = new Node(p->next->val);
                listmap[p] = index;
                newmap[index] = q;
                index++;
                p = p->next;
                q = q->next;
            }
            else{
                listmap[p] = index;
                newmap[index] = q;
                q->next = nullptr;
                p = p->next;
                q = q->next;
            }
        }

        for(q = new_head, p = head; p || q; p = p->next, q = q->next){
            if(p->random == nullptr) { q->random = nullptr; continue;}
                
            int random_index = listmap[p->random];
            q->random = newmap[random_index];
        }

        return new_head;
    }
};