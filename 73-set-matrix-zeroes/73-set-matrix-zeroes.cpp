class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int k=matrix[0].size();
        unordered_map<int,int>mp_row,mp_column;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(matrix[i][j]==0){

                mp_row[i]++;
                    mp_column[j]++;
                }else{
                    continue;
                }
                
                
        }
            
            
        
        
    }
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(mp_row[i]>0 || mp_column[j]>0){
                    matrix[i][j]=0;
                }else{
                    continue;
                }
                
            }}
    }
        
        
};