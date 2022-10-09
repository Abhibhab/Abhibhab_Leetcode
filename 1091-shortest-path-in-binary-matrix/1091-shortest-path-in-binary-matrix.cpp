class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size=grid.size();
        vector<vector<int>>dist(size,vector<int>(size,1e9));
        if(grid[0][0]==1 || grid[size-1][size-1]==1)return -1;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        dist[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=row+i;
                    int ncol=col+j;
                    if(nrow<size && ncol<size && nrow>=0 && ncol>=0 ){
                        if(grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol] ){
                        dist[nrow][ncol]=dis+1;
                        q.push({dis+1,{nrow,ncol}});
                        }
                    }
                    
                    
                }
            }
        
        }
        if(dist[size-1][size-1]==1e9)return -1;
        else return dist[size-1][size-1];
         
        
    }
};