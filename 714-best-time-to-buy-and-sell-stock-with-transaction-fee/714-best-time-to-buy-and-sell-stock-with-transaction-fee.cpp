class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
           // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        // return helper(0,1,prices,dp);
                // vector<vector<int>>dp(prices.size(),vector<int>(2,0));
        
       vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        // int n=prices.size();
        // dp[n][0] = dp[n][1] = 0;
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++ ){
                   if(buy){
            dp[index][buy]= max((-prices[index]-fee)+dp[index+1][0],dp[index+1][1]);            
        }else{
         dp[index][buy] =max(+prices[index]+dp[index+1][1],0+dp[index+1][0]);            

            
                
            }
        }
            
        

        

    }
        return dp[0][1];
    }
};