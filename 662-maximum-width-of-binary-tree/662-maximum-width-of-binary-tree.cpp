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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>que;
        if(root==NULL)return 0;
        que.push({root,0});
        long long ans=0;
        while(!que.empty()){
            long long size=que.size();
            long long curmin=que.front().second;
            long long leftmost,rightmost;
            for(int i=0;i<size;i++){
                long long cur_id=que.front().second-curmin;
                TreeNode* hi=que.front().first;
                que.pop();
                if(i==0)leftmost=cur_id;
                if(i==size-1)rightmost=cur_id;
                if(hi->left){
                    que.push({hi->left,(cur_id*2)+1});
                }
                if(hi->right){
                    que.push({hi->right,(cur_id*2)+2});
                }
            }
            ans=max(ans,(rightmost-leftmost)+1);
            
        }
        return ans;
        
    }
};