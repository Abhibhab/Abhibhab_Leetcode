class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>vec(arr.size(),-1);
        return helper(0,arr,k,vec);
      
        
    }
    int helper(int ind,vector<int>&arr,int k, vector<int>&vec){
        int n=arr.size();
        if(ind==n)return 0;
        if(vec[ind]!=-1)return vec[ind];
        int maxi=INT_MIN;
        int curr=INT_MIN;
        int length=0;
        for(int i=ind;i < min(n, ind + k) ;i++){
            curr=max(arr[i],curr);
            length++;
            int ans=length*curr+helper(i+1,arr,k,vec);
            maxi=max(maxi,ans);
            
            
            
        }
        return vec[ind]=maxi;
    }
};