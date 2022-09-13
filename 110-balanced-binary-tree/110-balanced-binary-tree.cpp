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
    bool isBalanced(TreeNode* root) {
        // if(root==NULL)return true;
        // int lh=height(root->left);
        // int rh=height(root->right);
        // if(abs(rh-lh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
        //     return true;
        // }else{
        //     return 0;
        // }
        int a=height(root);
        if(a==-1)return false;
        else return true;
    }
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int lh=height(root->left);
        if(lh==-1)return -1;
        int rh=height(root->right);
        if(rh==-1)return -1;
        if(abs(rh-lh)>1)return -1;
        return max(lh,rh)+1;
        
    }
};