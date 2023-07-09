//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

  int helper(int ind,vector<int>&heights,vector<int>&dp){
      if(ind<=0)return 0;
      if(dp[ind]!=-1)return dp[ind];
      int option1=helper(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
      int option2=INT_MAX;
      if(ind>=2)option2=helper(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
      return dp[ind]=min(option1,option2);
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,-1);
        return helper(n-1,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends