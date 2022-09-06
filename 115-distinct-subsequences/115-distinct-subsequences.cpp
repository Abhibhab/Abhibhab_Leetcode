// #define int long long

class Solution {
public:
    int numDistinct(string s, string t) {
          if (s.empty() || t.empty() || s.size() < t.size()) return 0;
        // vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,-1));
        // return helper(s.size(),t.size(),s,t,dp);
     vector<vector<double>>dp(s.size()+1,vector<double>(t.size()+1,0));
        for(int i=0;i<=s.size();i++)dp[i][0]=1;
        
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){

                     if(s[i-1]==t[j-1]){
                   int leave=dp[i-1][j-1];
                    int  stay=dp[i-1][j];
                   dp[i][j]=(leave+stay)%1000000007 ;
            
                  }else{
                    dp[i][j]= dp[i-1][j];
            
        }
                    
                
            }
        }
        return (int)dp[s.size()][t.size()];

        
    }
    int helper(int i,int j,string s,string t,  vector<vector<int>>&dp){
        if(j==0)return 1;
        if(i==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i-1]==t[j-1]){
            int leave=helper(i-1,j-1,s,t,dp);
            int stay=helper(i-1,j,s,t,dp);
            return dp[i][j]=leave+stay;
            
        }else{
            return helper(i-1,j,s,t,dp);
            
        }
    }
};