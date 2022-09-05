class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=1;
        }
        for(int ind=1;ind<coins.size();ind++){
            for(int amo=0;amo<=amount;amo++){
                 int take=0;
        if(amo>=coins[ind])take=dp[ind][amo-coins[ind]];
        int notake=dp[ind-1][amo];
        dp[ind][amo]= take+notake;
                
            }
        }
        return dp[coins.size()-1][amount];
        // return helper(coins.size()-1,amount,coins);
        
    }
    int helper(int ind,int amount,vector<int>&coins){
        if(ind==0)return (amount%coins[0]==0);
        int take=0;
        if(amount>=coins[ind])take=helper(ind,amount-coins[ind],coins);
        int notake=helper(ind-1,amount,coins);
        return take+notake;
    }
};