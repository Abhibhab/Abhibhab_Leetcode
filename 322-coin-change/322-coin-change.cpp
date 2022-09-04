class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>vec(coins.size(),vector<int>(amount+1,-1));
        int ans= helper(coins.size()-1,coins,amount,vec);
        if(ans>=1e9){
            return -1;
        }else{
            return ans;
        }
        
    }
    int helper(int index,vector<int>&coins,int amount,vector<vector<int>>&vec){
        if(index==0){
            if(amount%coins[0]==0)return amount/coins[0];
            else return 1e9;
            
            // if(amount%coins[0]==0)return amount/coins[0];
            // else return 0;
        }
        if(vec[index][amount]!=-1)return vec[index][amount];
        int take=INT_MAX;
        if(coins[index] <= amount) 
            take = 1 + helper(index,coins,amount-coins[index],vec);
        int notake=helper(index-1,coins,amount,vec);
        
        return vec[index][amount]=min(notake,take);
    }
};