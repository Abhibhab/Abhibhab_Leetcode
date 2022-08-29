
class Solution {
public:
    int helper(int n,vector<int>&ans){
        if(n<=0) return 1;
        if(n==1){
            return 1;
        }
        if(ans[n]!=-1){
            return ans[n];
        }else{
        int small=helper(n-1,ans);
        int small2=helper(n-2,ans);
        // int small3=climbStairs(n-3);
       ans[n]=small+small2;
            return ans[n];
        }
        
    }
    int climbStairs(int n) {
        vector<int>vec(50);
        for(int i=0;i<50;i++){
            vec[i]=-1;
        }
        return helper(n,vec);

        

        
        
        
    }
};