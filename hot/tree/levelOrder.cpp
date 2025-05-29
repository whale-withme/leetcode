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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)   return vector<vector<int>>();

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.emplace(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> tmp;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                tmp.emplace_back(node->val);
                if(node->left)  q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;

        // if(!root)   return vector<vector<int>>();

        // queue<pair<TreeNode*, int>> q;
        // vector<pair<int, int>> record;
        // vector<vector<int>> ans;
        // q.emplace(root, 0);

        // while(!q.empty()){
        //     TreeNode *front = q.front().first;
        //     record.emplace_back(front->val, q.front().second);

        //     if(front->left)     q.emplace(front->left, q.front().second+1);
        //     if(front->right)     q.emplace(front->right, q.front().second+1);
        //     q.pop();
        // }

        // vector<int> tmp;
        // for(int i = 0; i < record.size(); i++){
        //     if(i && record[i].second != record[i-1].second){
        //         ans.push_back(tmp);
        //         tmp.clear();
        //         tmp.push_back(record[i].first);
        //     }
        //     else if(i == 0){
        //         tmp.push_back(record[0].first);
        //         ans.push_back(tmp);
        //         tmp.clear();
        //     }
        //     else{
        //         tmp.push_back(record[i].first);
        //     }
        // }
        // return ans;
    }
};