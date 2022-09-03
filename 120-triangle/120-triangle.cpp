class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>&dp){
        if(i==n-1)
            return triangle[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int diag=triangle[i][j]+helper(i+1,j+1,triangle,n,dp);
        int down=triangle[i][j]+helper(i+1,j,triangle,n,dp);
        return dp[i][j]= min(diag,down);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int size=triangle.size();
        vector<vector<int>>dp(size,vector<int>(size,-1));
        return helper(0,0,triangle,size,dp);
        
    }
};
