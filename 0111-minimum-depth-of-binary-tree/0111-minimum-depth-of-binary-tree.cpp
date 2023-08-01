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
public:
    int solve(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int leftHeight= solve(root->left);
        int rightHeight= solve(root->right);
        
        if(leftHeight==0 || rightHeight==0)
        return max(leftHeight, rightHeight) +1;

        return min(leftHeight, rightHeight) + 1;
    }
    int minDepth(TreeNode* root) {
        //simply we will take shortest length from root to leaf---
        return solve(root);
    }
};