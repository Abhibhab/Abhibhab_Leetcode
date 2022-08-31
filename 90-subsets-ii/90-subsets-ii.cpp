class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subs;
        sort(nums.begin(),nums.end());
        helper(nums,0,subs);
        return ans;
        
        
    }
    void helper(vector<int>&nums,int index,vector<int>&subs){
        ans.push_back(subs);
        
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]) continue;
            subs.push_back(nums[i]);
            helper(nums,i+1,subs);
            subs.pop_back();
    }
        
    }
};