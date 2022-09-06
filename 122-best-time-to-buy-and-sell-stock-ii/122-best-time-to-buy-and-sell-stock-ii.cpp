class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(0,1,prices,dp);
                // vector<vector<int>>dp(prices.size(),vector<int>(2,0));

    }
    int helper(int index,int buy,vector<int>&prices, vector<vector<int>>&dp){
        if(index==prices.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        if(buy){
            return dp[index][buy]= max(-prices[index]+helper(index+1,0,prices,dp),0+helper(index+1,1,prices,dp));            
        }else{
         return dp[index][buy] =max(+prices[index]+helper(index+1,1,prices,dp),0+helper(index+1,0,prices,dp));            

            
            
        }
    }
};