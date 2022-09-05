class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return helper(word1.size(),word2.size(),word1,word2,dp);
        
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