class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);        
        int size=nums.size();
        vector<vector<int>>dp(size,vector<int>(sum+1,-1));
        if(sum%2==0) return helper(size-1,nums,sum/2,dp);
        else return false;
        
    }
    bool helper(int i,vector<int>&nums,int sum,vector<vector<int>>&dp){
        if(i==0){
            if(nums[i]==sum || sum==0) return true;
            return false;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int take=false;
        if(sum>=nums[i]){
            take=helper(i-1,nums,sum-nums[i],dp);
        }
        int notake=helper(i-1,nums,sum,dp);
        return dp[i][sum]=notake||take;
        
    }
};