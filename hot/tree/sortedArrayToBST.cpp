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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    TreeNode* helper(vector<int>& arr, int start, int end){
        if(start > end) return nullptr;

        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = helper(arr, start, mid-1);
        root->right = helper(arr, mid+1, end);

        return root;
    }
};