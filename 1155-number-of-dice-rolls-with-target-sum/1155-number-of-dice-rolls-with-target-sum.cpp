class Solution {
public:
    int helper(int sum,int n,int k,int target, vector<vector<int>>&dp){
        
        if(n==0){
            if(sum==target)return 1;
            else return 0;
            
        }
        if(dp[n][sum]!=-1)return dp[n][sum];
        int ans=0;
        for(int i=1;i<=k;i++){
            if(sum+i<=target){
            ans=(ans+helper(sum+i,n-1,k,target,dp))% 1000000007;
            }
            
        }
        return dp[n][sum]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return helper(0,n,k,target,dp);
        
    }
};