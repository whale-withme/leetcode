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

 /*
class LRUCache {
public:
    unordered_map<int, Node*> map;
    int cap = -1, size = 0;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(map.count(key) != 0){
            int val = map[key]->val;
            Node* newnode = new Node(key, val);
            remove(map[key]);
            add(newnode);
            map[key] = newnode;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key) != 0){
            int val = map[key]->val;
            Node* newnode = new Node(key, value);
            remove(map[key]);
            add(newnode);
            map[key] = newnode;
        }else{
            if(size < cap){
                Node* newnode = new Node(key, value);
                map[key] = newnode;
                add(newnode);
                size++;
            }else{
                Node* lastNode = tail->pre;
                map.erase(lastNode->key);
                removeLast();
                Node* newnode = new Node(key, value);
                add(newnode);
                map[key] = newnode;
            } 
        }
    }

    void remove(Node* cur){
        Node* preNode = cur->pre;
        preNode->next = cur->next;
        cur->next->pre = preNode;
        cur->pre = cur->next = nullptr;
    }

    void add(Node* cur){
        cur->next = head->next;
        head->next->pre = cur;
        head->next = cur;
        cur->pre = head;
    }

    void removeLast(){
        Node* gc = tail->pre;
        tail->pre->pre->next = tail;
        tail->pre = tail->pre->pre;
    }
};
 
 */