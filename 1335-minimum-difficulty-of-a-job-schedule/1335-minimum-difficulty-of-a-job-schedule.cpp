class Solution {
public:
    int helper(int i,int d,vector<int>&dif,vector<vector<int>>&dp){
        int size=dif.size();
        if(i==size && d==0)return 0;
        if(i==size||d==0)return 1e9;
        if(dp[i][d]!=-1)return dp[i][d];
        int ans=INT_MAX;
        int maxi=INT_MIN;
        for(int j=i;j<size;j++){
            maxi=max(maxi,dif[j]);
            ans=min(ans,maxi+helper(j+1,d-1,dif,dp));
            
        }
        return dp[i][d]=ans;
        
        
    }
    int minDifficulty(vector<int>& jD, int d) {
        int n=jD.size();
        if(n<d)      
            return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return helper(0,d,jD,dp);
        
    }
};