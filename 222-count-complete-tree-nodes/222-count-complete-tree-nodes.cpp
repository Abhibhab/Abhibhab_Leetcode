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
    // int count=0;
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int left=0,right=0;
       left=heightl(root);
       right=heightr(root);
        if(left==right)return (1<<left)-1;
        return 1+countNodes(root->right)+countNodes(root->left);

        
//         if(root->left){
//             left=countNodes(root->left);
            
//         }
//         if(root->right){
//             right=countNodes(root->right);
            
//         }
//         return left+right+1;
        
        
    }
    int heightr(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
        
    }
     int heightl(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->left;
        }
        return count;
        
    }
//     int findHeightLeft(TreeNode* cur) {
//         int hght = 0; 
//         while(cur) {
//             hght++; 
//             cur = cur->left; 
//         }
//         return hght; 
//     }
//     int findHeightRight(TreeNode* cur) {
//         int hght = 0; 
//         while(cur) {
//             hght++; 
//             cur = cur->right; 
//         }
//         return hght; 
//     }
//     int countNodes(TreeNode* root) {
//         if(root == NULL) return 0; 
        
//         int lh = findHeightLeft(root); 
//         int rh = findHeightRight(root); 
        
//         if(lh == rh) return (1<<lh) - 1; 
        
//         int leftNodes = countNodes(root->left);
//         int rightNodes = countNodes(root->right);
        
//         return 1 + leftNodes + rightNodes; 
//     }
};