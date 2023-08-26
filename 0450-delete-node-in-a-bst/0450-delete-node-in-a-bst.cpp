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
    int findMax(TreeNode* root){
        if(!root){
            return -1;
        }
        while(root->right)
         root= root->right;

        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
            return NULL;
        }

        if(root->val==key){
            //need to be deleted---
            if(!root->right && !root->left){
                // delete root;
                return NULL;
            }
            if(root->left && !root->right){
                TreeNode* child= root->left;
                // delete root;
                return child;
            }else if(!root->left && root->right){
                TreeNode* child= root->right;
                // delete root;
                return child;
            }else{

                    int nextPred= findMax(root->left);
                    root->val= nextPred;
                    root->left= deleteNode(root->left, nextPred);
                    return root;
            }

        }else if(key<root->val){
            root->left= deleteNode(root->left, key);
        }else{
            root->right= deleteNode(root->right, key);
        }

        return root;
    }
};