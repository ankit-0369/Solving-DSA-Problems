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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int h=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            
            TreeNode* temp= q.front();
            q.pop();
            if(temp){

                if(temp->left) q.push(temp->left);
                
                if(temp->right) q.push(temp->right);
                
            }else{
                h++;
                if(!q.empty())  //important as we push null to seperate levels if q will empty then no more levels-
                q.push(NULL);
                
            }
        }
        
        return h;
    }
};