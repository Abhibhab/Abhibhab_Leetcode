class Solution {
public:
    
    int helper(int i,int j,int m,int n,vector<vector<int>>&ans){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0)return 0;
        
        if(ans[i][j]!=-1) return ans[i][j];
        
         int left=helper(i,j-1,m,n,ans);
         int up=helper(i-1,j,m,n,ans);
        return ans[i][j]=left+up;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>vec(m,vector<int>(n,-1));
        
        
        return helper(m-1,n-1,m,n,vec);
        
    }
};