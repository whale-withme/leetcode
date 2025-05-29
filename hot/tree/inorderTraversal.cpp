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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>();
        vector<int> ans;
        traverse(ans, root);
        return ans;
    }

    void traverse(vector<int> &arr, TreeNode* root){
        if(root->left != nullptr)
            traverse(arr, root->left);

        if(root->left == nullptr && root->right == nullptr){
            arr.push_back(root->val);
            return ;
        }

        arr.push_back(root->val);
        if(root->right != nullptr)
            traverse(arr, root->right);
        
    }
};