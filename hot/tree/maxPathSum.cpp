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
    int maxLen = INT_MIN;

    int maxPathSum(TreeNode* root) {
        int tmp = maxhelper(root);
        return maxLen;
    }

    int maxhelper(TreeNode* node){
        if(!node)
            return 0;
        if(node->left == nullptr && node->right == nullptr){
            maxLen = max(node->val, maxLen);
            return node->val;
        }
        int left = max(0, maxhelper(node->left));
        int right = max(0, maxhelper(node->right));

        maxLen = max(maxLen, node->val+left+right);
        return node->val + max(left, right);    // 也可能子节点都是负数，不选子节点也可以
    }
};