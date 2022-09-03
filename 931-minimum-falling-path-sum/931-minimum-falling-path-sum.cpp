class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& memo){
        if( j<0 || j>=matrix.size()){
            return 1e9;
        }
        if(i==0){
            return matrix[i][j];
        }
        if(memo[i][j]!=-1) return memo[i][j];
        
       
        int option1=matrix[i][j]+helper(i-1,j-1,matrix,memo);
        int option2=matrix[i][j]+helper(i-1,j,matrix,memo);
        int option3=matrix[i][j]+helper(i-1,j+1,matrix,memo);
        return memo[i][j]=min(option1,min(option2,option3));

    
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=INT_MAX;
        // vector<vector<int>>memo(matrix.size(),vector<int>(matrix.size(),-1));
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix.size(),0));
        int size=matrix.size();
        for(int j=0;j<size;j++)dp[0][j]=matrix[0][j];
        for(int i=1;i<size;i++){
            for(int j=0;j<size;j++){
                int option1=1e9,option2=1e9,option3=1e9;
                option1=matrix[i][j]+dp[i-1][j];//up;
                if(j>0){
                    option2=matrix[i][j]+dp[i-1][j-1];
                }
                if(j<size-1){
                    option3=matrix[i][j]+dp[i-1][j+1];
                    
                }
                dp[i][j]=min(option1,min(option2,option3));
                
            }
        }
    for(int j=0;j<size;j++){
        mini=min(mini,dp[size-1][j]);
    }
        return mini;

        // for(int j=0;j<matrix.size();j++){
        //     mini=min(mini,helper(matrix.size()-1,j,matrix,memo));
        // }   
        // return mini;
    }
};