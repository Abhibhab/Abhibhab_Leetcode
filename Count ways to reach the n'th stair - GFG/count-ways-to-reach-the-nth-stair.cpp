//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    long long helper(int n,vector<long long>&dp){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n]%mod;
        long long way1=helper(n-1,dp);
        long long way2=helper(n-2,dp);
        return dp[n]=(way1+way2)%mod;
    }
    int countWays(int n)
    {
        // your code here
        // vector<long long>dp(n+1,-1);
        // return helper(n,dp);
        //tabular
        // vector<long long>dp(n+1,-1);
        // dp[0]=1;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=(dp[i-1]+dp[i-2])%mod;
        // }
        // return dp[n]%mod;
        //Two Var
        long long prev=1;
        long long prev2=1;
        for(int i=2;i<=n;i++){
            long long cur=(prev+prev2)%mod;
            prev2=prev;
            prev=cur;
            
        }
         return prev%mod;        
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends