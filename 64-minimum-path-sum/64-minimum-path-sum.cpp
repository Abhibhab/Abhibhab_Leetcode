class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 && j==0)return grid[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int left=grid[i][j]+helper(i,j-1,grid,dp);
        int up=grid[i][j]+helper(i-1,j,grid,dp);
        return dp[i][j]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) { 
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {dp[i][j]=grid[i][j];continue;}
                int left=1e9,right=1e9;
                if(i>0){
                    left=grid[i][j]+dp[i-1][j];
                }
                if(j>0){
                    right=grid[i][j]+dp[i][j-1];
                }
                dp[i][j]=min(right,left);
                
                
            }
        }
        return dp[m-1][n-1];
        // return helper(m-1,n-1,grid,dp);
        
    }
};