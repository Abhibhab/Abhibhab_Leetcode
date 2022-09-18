/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    map<TreeNode*,TreeNode*>par;
    map<TreeNode*,bool>vis;
    
public:
    
    void markParents(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           TreeNode* bro=q.front();
            q.pop();
            if(bro->left){
                par[bro->left]=bro;
                q.push(bro->left);
            }
            if(bro->right){
                par[bro->right]=bro;
                q.push(bro->right);
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int cur=0;
        while(!q.empty()){
            if(cur==k)break;
            cur++;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t->left && !vis[t->left]){
                    q.push(t->left);
                    vis[t->left]=true;
                }
                if(t->right && !vis[t->right]){
                    q.push(t->right);
                    vis[t->right]=true;
                }
                if(par[t] && !vis[par[t]]){
                    q.push(par[t]);
                    vis[par[t]]=true;
                }
                
                
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* hi=q.front();
            q.pop();
            ans.push_back(hi->val);
        }
        return ans;
        
    }
};