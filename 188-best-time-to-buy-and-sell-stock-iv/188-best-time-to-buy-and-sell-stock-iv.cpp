class Solution {
public:
    int maxProfit(int k,vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,k,prices,dp);
        
    }
    int helper(int index,int buy,int k,vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(index==prices.size() || k==0)return 0;
        if(dp[index][buy][k]!=-1)return dp[index][buy][k];
         if(buy){
            return dp[index][buy][k]= max(-prices[index]+helper(index+1,0,k,prices,dp),0+helper(index+1,1,k,prices,dp));            
        }else{
         return dp[index][buy][k]= max(+prices[index]+helper(index+1,1,k-1,prices,dp),0+helper(index+1,0,k,prices,dp));            

    }
    }
};