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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root){
            vector<int>vec;
            return vec;
        }
        vector<int>vec=inorderTraversal(root->left);
        vec.push_back(root->val);
        vector<int>helo=inorderTraversal(root->right);
        for(auto it:helo){
            vec.push_back(it);
        }
        return vec;
    }
};