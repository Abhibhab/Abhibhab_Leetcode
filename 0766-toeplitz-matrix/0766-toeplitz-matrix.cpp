class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int first=matrix[i][j];
                int k=i,l=j;
                while(k<matrix.size() && l<matrix[0].size()){
                    if(matrix[k][l]!=first){
                        return false;
                    }
                    k++;
                    l++;
                }
            }
        }
        return true;
        
    }
};