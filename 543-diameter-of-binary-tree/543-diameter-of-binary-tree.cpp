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
    int maxi=INT_MIN;
     int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
         maxi=max(maxi,lh+rh);
        return max(lh,rh)+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int i= maxDepth(root);
        return maxi;
        // return max((maxDepth(root->left)+maxDepth(root->right)),max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        
    }
};