#include <bits/stdc++.h>
using namespace std;

class LRUCache {
typedef struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;

    Node(){
        pre = nullptr;
        next = nullptr;
    }
    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
    Node(int key, int val, Node* pre, Node* next){
        this->key = key;
        this->val = val;
        this->pre = pre;
        this->next = next;
    }
}Node;

Node* head = nullptr, *tail = nullptr;

unordered_map<int, Node*> map;  
int cap = -1;

public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
        cap = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end())
            return -1;

        Node* iter = map[key];
        remove(iter);
        add(iter);
        return iter->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) == map.end()){
            Node* p = new Node(key, value);
            if(map.size() == cap){
                Node* last = tail->pre;
                removeLast();
                map.erase(last->key);
                delete(last);
            }
            add(p);
            map[key] = p;
        }else{
            Node* p = map[key];
            p->val = value;
            remove(p);
            add(p);   
        }
    }
private:
    void remove(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void add(Node* node){
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
        node->pre = head;
    }

    void removeLast(){
        tail->pre->pre->next = tail;
        tail->pre = tail->pre->pre;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */