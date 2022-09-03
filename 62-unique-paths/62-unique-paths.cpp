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
        vector<vector<int>>vec(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) vec[i][j]=1;
                else{
                    int left=0,up=0;
                    if(j>0){
                        left=vec[i][j-1];
                        
                    }
                    if(i>0){
                        up=vec[i-1][j];
                    }
                    vec[i][j]=left+up;
                        
                    
                }
            }
        }
        return vec[m-1][n-1];
        
        
        // return helper(m-1,n-1,m,n,vec);
        
    }
};