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
    void solve(TreeNode* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        solve(root->left, ans);
        solve(root->right, ans);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //using recursion--- O(n) and space- O(n)
        // vector<int> ans;
        // solve(root, ans);
        // return ans;

        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur= st.top();
            st.pop();
            if(cur){
                ans.push_back(cur->val);
                st.push(cur->right);
                st.push(cur->left);

            }
        }
        return ans;
    }
};