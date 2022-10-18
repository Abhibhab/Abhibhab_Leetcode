class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size=nums.size();
        
        vector<int>ans(size,-1);
        stack<int>st;
        for(int i=0;i<2*size;i++){
            int num=nums[i%size];
            while(st.size() && nums[st.top()]<num){
                ans[st.top()]=num;
                st.pop();
                
            }
            if(i<size) st.push(i);
        }
        return ans;
//         for(int i=size-1;i>=0;i--){
//             if(st.empty()){
//                 ans.push_back(-1);
//             }else{
//                 int ele=st.top();
//                 if(ele>nums[i]){
//                     ans.push_back(ele);
//                 }else{
//                     while(st.size() && st.top()<=nums[i]){
//                         st.pop();
//                     }
//                     if(st.empty()){
//                         ans.push_back(-1);
//                     }else{
//                         ans.push_back(st.top());
//                     }
//                 }
//             }
//             st.push(nums[i]);
            
            
//         }
//         reverse(ans.begin(),ans.end());
//         // if(nums[size-1]!=*max_element(nums.begin(),nums.end())){
//         //     ans[size-1]=*max_element(nums.begin(),nums.end());
//         // }
//         return ans;
        
    }
};