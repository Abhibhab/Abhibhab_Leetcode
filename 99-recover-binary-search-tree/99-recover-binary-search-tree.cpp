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
    // vector<TreeNode*>vec;
    TreeNode* first;
    TreeNode* prev;
    TreeNode* curr;
    TreeNode* last; 
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
       
        if(prev!=NULL && root->val<prev->val){
            if(first==NULL){
                first=prev;
                curr=root;
            }else{
                last=root;
            }
            
        }else{
            prev=root;
        }
        
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)return ;
//         TreeNode* prev=NULL,curr=NULL,next=NULL,last=NULL;
//         for(int i=1;i<vec.size();i++){
//             if(vec[i]->val>vec[i-1]->val){
//                 if(prev==NULL){
//                     prev=vec[i-1];
//                     curr=vec[i];
                    
                    
//                 }else{
//                     last=vec[i];
//                 }
                
//             }
            
            
//         }
        inorder(root);
        if(first!=NULL && last!=NULL){
            swap(first->val,last->val);
        }else if(first!=NULL && curr!=NULL){
            swap(first->val,curr->val);
        }
        
        
        
    }
};