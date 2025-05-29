#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> father;
    unordered_set<TreeNode*> path;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);

        while(p != nullptr){
            path.insert(p);
            p = father[p];
        }

        while(q){
            if(path.find(q) != path.end())
                return q;
            q = father[q];
        }

        return nullptr;
    }

    void dfs(TreeNode* root){
        if(root->left)  { father[root->left] = root; dfs(root->left); }
        if(root->right) { father[root->right] = root; dfs(root->right); } 
    }
};