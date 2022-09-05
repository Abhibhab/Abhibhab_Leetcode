class Solution {
public:
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        // return helper(word1.size(),word2.size(),word1,word2,dp);
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));
        dp[0][0]=0;
        for(int i=0;i<=word1.size();i++)dp[i][0]=i;
        for(int i=0;i<=word2.size();i++)dp[0][i]=i;
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                 if(word1[i-1]==word2[j-1]){
          dp[i][j]=dp[i-1][j-1];
        }else{
          dp[i][j]= min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
        }
                
            }
        }
        return dp[word1.size()][word2.size()];
        

        
    }
    int helper(int i,int j,string str1,string str2,vector<vector<int>>&dp){
        if(i==0 || j==0){
            if(i==0 && j==0) return 0;
           return max(i,j);
                        
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(str1[i-1]==str2[j-1]){
            return dp[i][j]=helper(i-1,j-1,str1,str2,dp);
        }else{
            return dp[i][j]= min(helper(i-1,j,str1,str2,dp),min(helper(i,j-1,str1,str2,dp),helper(i-1,j-1,str1,str2,dp)))+1;
        }
        
        
    }
};