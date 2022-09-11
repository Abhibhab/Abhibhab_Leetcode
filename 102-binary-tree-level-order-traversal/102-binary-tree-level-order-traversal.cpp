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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            vector<vector<int>>ans;
            return ans;
        }
        vector<vector<int>>ans;
        queue<TreeNode*>que;
        que.push(root);
        while(que.size()>0){
            int size=que.size();
            vector<int>vec;
            for(int i=0;i<size;i++){
                TreeNode* valu=que.front();
                que.pop();
                vec.push_back(valu->val);
                if(valu->left){
                    que.push(valu->left);
                }
                if(valu->right){
                    que.push(valu->right);
                }
                
                
            }
            ans.push_back(vec);
        }
        return ans;
        
    }
};