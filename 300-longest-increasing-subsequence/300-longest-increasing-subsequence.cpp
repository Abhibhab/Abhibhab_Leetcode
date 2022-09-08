class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        // return helper(0,-1,nums,dp);
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,0));
        int ans=1;
        vector<int>dp(nums.size(),1);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                    
                }
            }
        }
        return ans;
        

        
    }
    int helper(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
        int taking=0;int nottaking;
        if(prev==-1 || nums[ind]>nums[prev]){
            taking=helper(ind+1,ind,nums,dp)+1;
            nottaking=helper(ind+1,prev,nums,dp)+0;
            
        }else{
            nottaking=helper(ind+1,prev,nums,dp)+0;
            
        }
        return dp[ind][prev+1]= max(taking,nottaking);
    }
};