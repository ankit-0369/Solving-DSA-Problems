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
    private:
      vector<int> ans;
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }

        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        //using recursion--t.c:- O(n) & space:- O(n)
        // dfs(root);
        // return ans;
        //using iteration---
        stack<TreeNode*> st1;
        if(root==NULL){
            return ans;
        }
        stack<int> st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* temp= st1.top();
            st1.pop();
            st2.push(temp->val);
            if(temp->left) st1.push(temp->left);

            if(temp->right) st1.push(temp->right);
        }

        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }

        return ans;
    }

};