class Solution {
public:
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // vector<vector<vector<int>>>dp(multipliers.size(),vector<vector<int>>(nums.size(),vector<int>(nums.size(),-1)));
        vector<vector<int>>dp(multipliers.size(),vector<int>(multipliers.size(),INT_MIN));
        return helper(0,0,nums.size()-1,multipliers.size(),nums,multipliers,dp);
        
    }
    int helper(int no,int start,int end,int m,vector<int>& nums, vector<int>& multipliers,  vector<vector<int>>&dp){
        if( no==m)return 0;
        if(dp[no][start]!=INT_MIN)return dp[no][start];
        int option1=0,option2=0;
        
        
        option1=(nums[start]*multipliers[no])+helper(no+1,start+1,end,m,nums,multipliers,dp);
        option2=(nums[end]*multipliers[no])+helper(no+1,start,end-1,m,nums,multipliers,dp);
        return dp[no][start]=max(option1,option2);
        
    
        
        
    }
};
// class Solution {
// public:
//     int rec(int idx,int st,int end,vector<int>& nums,vector<int>& multi,vector<vector<int>> &dp){
//         if(idx==multi.size()) return 0;
//         if(dp[idx][st]!=INT_MIN) return dp[idx][st];
//         int ans=INT_MIN;
//         ans= max(multi[idx]*nums[st]+ rec(idx+1,st+1,end,nums,multi,dp),
//                 multi[idx]*nums[end]+ rec(idx+1,st,end-1,nums,multi,dp));
//         return dp[idx][st]= ans;
//     }
//     int maximumScore(vector<int>& nums, vector<int>& multi) {
//         vector<vector<int>> dp(multi.size(),vector<int>(multi.size(),INT_MIN));
//         return rec(0,0,nums.size()-1,nums,multi,dp);
//     }
// };