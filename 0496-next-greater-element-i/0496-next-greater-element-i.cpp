class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>vec;
        stack<int>st;
        int size=nums2.size();
        
        for(int i=size-1;i>=0;i--){
            int ele=nums2[i];
            if(st.empty()){
                vec.push_back(-1);
            }else{
                while(!st.empty() && st.top()<=ele){
                    st.pop();
                }
                if(st.empty()){
                    vec.push_back(-1);
                }else{
                    vec.push_back(st.top());
                }
            }
            st.push(ele);
        }
        reverse(vec.begin(),vec.end());
        unordered_map<int,int>mp;
        for(int i=0;i<size;i++){
           mp.insert({nums2[i],vec[i]});
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
        
        // return vec;
//         stack<int>NGE;
//         int size1=nums2.size();
//         vector<int>vec;
//         for(int i=size1-1;i>=0;i--){
//             int num=nums2[i];
//             // if(NGE.empty()){
//             //     vec[i]=-1 ;           
//             // }else{
//                 int top=NGE.top();
//                 // if(top>num){
//                 //     vec[i]=top;
//                 // }else{
//                     // NGE.pop();
//                     while(NGE.top()<=num && NGE.size()){
//                         NGE.pop();
//                     }
//                     if(NGE.size()){
//                        vec.push_back(NGE.top());
//                     }else{
//                        vec.push_back(-1);
//                     }
//                 // }
//             // }
//             NGE.push(num);
            
//         }
//         return vec;
        
    }
};