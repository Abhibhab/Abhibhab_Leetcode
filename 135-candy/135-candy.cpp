class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()<=1)return 1;
        vector<int>arr(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1])arr[i]=arr[i-1]+1;
        }
        for(int i=ratings.size()-1;i>0;i--){
             if(ratings[i-1]>ratings[i])
			 arr[i-1]=max(arr[i]+1,arr[i-1]);
        }
        // for(auto it:arr){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return accumulate(arr.begin(),arr.end(),0);
    }
};