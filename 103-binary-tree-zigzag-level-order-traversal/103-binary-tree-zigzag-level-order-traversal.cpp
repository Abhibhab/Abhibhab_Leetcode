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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return{};
        int flag=0;
        queue<TreeNode*>que;
        que.push(root);
        vector<vector<int>>ans;
        while(!que.empty()){
            vector<int>vec;
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* hi=que.front();
                que.pop();
                vec.push_back(hi->val);
                if(hi->left)que.push(hi->left);
                if(hi->right)que.push(hi->right);
                
            }
            if(flag){
                reverse(vec.begin(),vec.end());
                ans.push_back(vec);
                
            }else{
                ans.push_back(vec);
                
            }
            flag=!flag;
            
        }
        return ans;
        
    }
};