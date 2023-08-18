/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //using recursion---
        vector<int> ans;
        // solve(root, ans);
        // return ans;
        //using iteration---
        stack<TreeNode*> st;
        TreeNode* cur= root;
        while(cur || !st.empty()){
         //jab tak left mile tab tak left me jao---
            while(cur){
                st.push(cur);
                cur= cur->left;
            }
            //cur node process ..process can be anything like adding in a vector or stack or using it  in some other logic
            cur= st.top();
             st.pop();
            //Now for trraversing right just push it in to the stack
             ans.push_back(cur->val);
            cur= cur->right;
           
        }

        return ans;
    }
};