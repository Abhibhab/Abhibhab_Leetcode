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
    vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        helper(root,targetSum,path);
        return ans;
    }
    void helper(TreeNode* root,int targetSum,vector<int>path){
        if(root==NULL)return ;
        
        if(root->left==NULL && root->right==NULL && targetSum==root->val){
            path.push_back(root->val);
            ans.push_back(path);
            return;
            
        }
        // if(root->val<=targetSum){
            path.push_back(root->val);
            if(root->left) helper(root->left,targetSum-root->val,path);
            if(root->right)helper(root->right,targetSum-root->val,path);
            path.pop_back();
        // }
    
    }
};