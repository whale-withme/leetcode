#include <bits/stdc++.h>
using namespace std;

class Trie {

    typedef struct Node{
        bool isend;
        unordered_map<char, Node*> child;
        
        Node(){
            isend = false;
        }
    }Node;

public:
    Node* root = nullptr;
    Trie() {
        root = new Node();

    }
    
    void insert(string word) {
        Node* node = root;
        for(auto c : word){
            if(node->child.find(c) == node->child.end()){
                node->child[c] = new Node();
            }
            node = node->child[c];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(auto c : word){
            if(node->child.find(c) == node->child.end())
                return false;
            node = node->child[c];
        }
        if(node->isend)
            return true;
        else
            return false;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(auto c : prefix){
            if(node->child.find(c) == node->child.end())
                return false;
            node = node->child[c];
        }
        if(!node->isend)
            return true;
        else
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */