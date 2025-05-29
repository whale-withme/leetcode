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
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++)
            index[inorder[i]] = i; // 记录中序遍历下值的索引
        return helperBuild(preorder, inorder, 0, n-1, 0, n-1);
    }

    TreeNode* helperBuild(vector<int> &preorder, vector<int> &inorder, int pre_start, int pre_end,
    int in_start, int in_end){

        if(pre_start > pre_end) return nullptr;

        int pre_root = pre_start;
        int in_root = index[preorder[pre_root]];  // 找到前序遍历根节点值对应索引
        
        TreeNode *root = new TreeNode(inorder[in_root]);
        int diff = in_root - in_start;
        root->left = helperBuild(preorder, inorder, pre_start, pre_start+diff, in_start, in_root-1);
        root->right = helperBuild(preorder, inorder, pre_start+diff+1, pre_end, in_root+1, in_end);

        return root;
    }
};