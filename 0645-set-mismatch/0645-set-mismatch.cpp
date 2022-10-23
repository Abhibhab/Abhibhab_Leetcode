class Solution {
public:
    vector<int> findErrorNums(vector<int>& vec) {
        // sort(vec.begin(),vec.end());
        // for(int i=1;i<=vec.size();i++){
        //     if(i!=vec[i-1]){
        //         return {vec[i-1],i};
        //     }
        // }
        // return {vec[0]};
        map<int,int>mp;
        for(int i=1;i<=vec.size();i++){
            mp[i]++;
        }
        for(auto it:vec){
            mp[it]++;
        }
        int a,b;
        for(auto it:mp){
            if(it.second==3){
                a=it.first;
            }
            if(it.second==1){
                b=it.first;
            }
            
        }
        return {a,b};
        
    }
};