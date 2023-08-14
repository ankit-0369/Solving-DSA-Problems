/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, TreeNode* p, stack<TreeNode*>& s){
        if(!root){
            return false;
        }

        if(root->val==p->val){
            s.push(root);
            return true;
        }
       bool left= path(root->left, p, s);
       bool right= path(root->right, p,s);
       if(left){
           s.push(root);
       }

    if(right)
    {
        s.push(root);

    }
    return (left || right);

    }

    TreeNode* naive(TreeNode* root, TreeNode* p, TreeNode* q){
          stack<TreeNode*> v1;
         path(root, p, v1);
        stack<TreeNode*> v2;
         path(root, q, v2);
        TreeNode* ans= NULL;
        
        while(!v1.empty() && !v2.empty()){
            if(v1.top()->val==v2.top()->val){
                ans= v1.top();
                
            }

            v1.pop();
            v2.pop();
        }

        return ans;
    }

    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root->val==p->val || root->val== q->val){
            return root;
        }

        TreeNode* left= solve(root->left, p,q);
        TreeNode* right= solve(root->right, p, q);
        if(left && right)
        return root;
        if(!left && right)
        return right;
        if(left && !right)
        return left;
       
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return naive(root, p, q);
        //optimized---
        return solve(root,p,q);
    }
};