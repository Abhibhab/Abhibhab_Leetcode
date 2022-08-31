class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>sha;
        helper(candidates,target,0,candidates.size(),sha);
        return ans;
        
    }
    void helper(vector<int>&candidates,int target,int index,int size,vector<int>&sha){
        if(index==size){
            if(target==0){
                ans.push_back(sha);
              
            }
            return;
    }
        if(candidates[index]<=target){
        sha.push_back(candidates[index]);
        helper(candidates,target-candidates[index],index,size,sha);
        sha.pop_back();
        }
        helper(candidates,target,index+1,size,sha);
    
    }
};