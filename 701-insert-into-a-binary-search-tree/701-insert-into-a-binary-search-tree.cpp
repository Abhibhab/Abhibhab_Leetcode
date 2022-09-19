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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* helo=new TreeNode(val);
            return helo;
        }
        TreeNode* temp=root;
        while(true){
            if(temp->val<val){
                if(temp->right==NULL){temp->right=new TreeNode(val);
                                      break;
                                     }else{
                    temp=temp->right;
                }
                
            }else{
                                if(temp->left==NULL){temp->left=new TreeNode(val);
                                      break;
                                     }else{
                    temp=temp->left;
                }
                
            }
            
        }
        return root;
//         if(root->val<val && root->right){
//             return insertIntoBST(root->right,val);
            
//         }
//         if(root->left){
//             return insertIntoBST(root->left,val);
//         }
      
            
        
        
    }
};