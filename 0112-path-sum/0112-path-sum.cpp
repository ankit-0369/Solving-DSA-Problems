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
    bool dfs(TreeNode* root, int pathSum, int tsum){
        if(!root){
            return false;
        }
        if(!root->left && !root->right){
           if( pathSum+ root->val==tsum){
               return true;
           }
            return false;
        }
        bool left= dfs(root->left, pathSum+root->val, tsum);
        bool right= dfs(root->right, pathSum+root->val, tsum);

        return (left|| right);
        

    }
    bool hasPathSum(TreeNode* root, int tsum) {
        if(!root)
        return false;
        int pathSum=0;
       return dfs(root,pathSum,tsum);

        // return (pathSum==tsum);

    }
};