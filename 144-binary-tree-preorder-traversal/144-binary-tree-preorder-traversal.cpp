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
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
       
    }
    void helper(TreeNode* root){
         if(root==NULL){
           return;
        }
        
        ans.push_back(root->val);
        TreeNode* temp=root;
            if(temp->left){
        
        preorderTraversal(temp->left);
            }
        if(temp->right){
        preorderTraversal(temp->right);
        }
      
        
        
    }
    
    // int helper()
};