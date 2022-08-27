class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) {
            vector<int>vec;
            vec.push_back(1);
            return vec;
        }
        vector<int>ans=getRow(rowIndex-1);
        vector<int>pop;
        pop.push_back(1);
        for(int i=1;i<ans.size();i++){
            pop.push_back(ans[i]+ans[i-1]);
            
        }
        pop.push_back(1);
        return pop;
        
    }
};