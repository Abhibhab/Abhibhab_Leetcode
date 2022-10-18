class Solution {
public:
    int largestRectangleArea(vector<int>& price) {
       // if(price[0]==1 && price[1]==1 && price.size()==2){
       //     return 2;
       // }
        // price.push_back(0);
        // price.insert(price.begin(),0);
    vector<int>span,span2;  
        int n=price.size();
       stack<int>st,st2;
       for(int i=0;i<n;i++){
           if(st.empty()){
               span.push_back(-1);
           }else{
               int num=price[st.top()];
               if(num<price[i]){
                   span.push_back(st.top());
               }else{
                   while(!st.empty() && price[st.top()]>=price[i]){
                       st.pop();
                   }
                   if(st.empty()){
                       span.push_back(-1);
                   }else{
                       span.push_back(st.top());
                   }
               }
           }
           st.push(i);
       }
              for(int i=n-1;i>=0;i--){
           if(st2.empty()){
               span2.push_back(n);
           }else{
               int num=price[st2.top()];
               if(num<price[i]){
                   span2.push_back(st2.top());
               }else{
                   while(!st2.empty() && price[st2.top()]>=price[i]){
                       st2.pop();
                   }
                   if(st2.empty()){
                       span2.push_back(n);
                   }else{
                       span2.push_back(st2.top());
                   }
               }
           }
           st2.push(i);
       }
        reverse(span2.begin(),span2.end());
        vector<int>width;
        for(int i=0;i<n;i++){
            width.push_back(span2[i]-span[i]-1);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int upto=width[i]*price[i];
            ans=max(ans,upto);
            ans=max(ans,price[i]);
           
        
       
        }
         return ans;
        
        
        
    }
};