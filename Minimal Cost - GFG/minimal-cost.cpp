//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int ind,int k,vector<int>&heights,vector<int>&dp){
        if(ind==0)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            if(ind-i>=0){
                ans=min(ans,helper(ind-i,k,heights,dp)+abs(heights[ind]-heights[ind-i]));
            }
            
        }
        return dp[ind]= ans;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return helper(n-1,k,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends