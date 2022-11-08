class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(high-low>1){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
                
            }else{
                low=mid;
                
            }
        }
        if(nums[high]==target){
            return high;
        }else if(nums[low]==target){
            return low;
        }else{
            return -1;
        }
        
    }
};