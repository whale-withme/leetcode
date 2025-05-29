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

    int maxDepth(TreeNode* root){
        if(!root)   return 0;
        int lh = maxDepth(root->left), rh = maxDepth(root->right);
        return max(lh, rh)+1;
    }
    // int maxDepth(TreeNode* root) {
    //     return deep(root, 0);
    // }

    // int deep(TreeNode *root, int cnt){
    //     if(root == nullptr) return cnt;
    //     return max(deep(root->left, cnt+1), deep(root->right, cnt+1));
    // }
};