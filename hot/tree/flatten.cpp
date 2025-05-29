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
    vector<TreeNode*> list;
    void flatten(TreeNode* root) {
        helper(root);
        if(!root)   return ;
        for(int i = 0; i < list.size(); i++){
            if(i != 0){
                TreeNode *pre = list[i-1];
                pre->right = list[i];
                pre->left = nullptr;
            }
        }
        list[list.size()-1]->left = nullptr;
        list[list.size()-1]->right = nullptr;
    }

    void helper(TreeNode* root){
        if(!root)   return ;
        // TreeNode *node = new TreeNode(root->val, nullptr, nullptr);
        list.push_back(root);
        helper(root->left);
        helper(root->right);
    }
};