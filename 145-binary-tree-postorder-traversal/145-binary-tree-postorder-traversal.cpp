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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){
            vector<int>vec;
            return vec;
        }
        vector<int>left=postorderTraversal(root->left);
        vector<int>right=postorderTraversal(root->right);
        for(auto it:right){
            left.push_back(it);
        }
        left.push_back(root->val);
        return left;
        
    }
};