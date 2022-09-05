class Solution {
public:
    int minDistance(string word1, string word2) {
        int k=LCS(word1,word2);
        return ((word1.size()-k)+(word2.size()-k));
        
    }
    int LCS(string text1, string text2) {
        int sizea=text1.size();
        int sizeb=text2.size();
        // vector<vector<int>>dp(sizea+1,vector<int>(sizeb+1,-1));
        // return helper(sizea,sizeb,text1,text2,dp);
        // vector<vector<int>>dp(sizea+1,vector<int>(sizeb+1,0));
        vector<int>prev(sizeb+1,0);
        vector<int>curr(sizeb+1,0);

        
       for(int i=1;i<=sizea;i++){
           for(int j=1;j<=sizeb;j++){
            if(text1[i-1]==text2[j-1])curr[j]=1 +prev[j-1];
            else curr[j]= max(prev[j],curr[j-1]);
               
           }
           prev=curr;
       }
        return prev[sizeb];   
        
        
    }
};