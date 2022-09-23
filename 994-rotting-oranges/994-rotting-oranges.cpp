class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>bfs;
        int cf=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    bfs.push({{i,j},0});
                    vis[i][j]=1;
                    
                }else if(grid[i][j]==1){
                    cf++;
                }
            }
        }
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        int ans=0;
        int count=0;
        
        while(!bfs.empty()){
            int row=bfs.front().first.first;
            int col=bfs.front().first.second;
            int level=bfs.front().second;
            ans=max(ans,level);
            bfs.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    bfs.push({{nrow,ncol},level+1});
                    vis[nrow][ncol]=1;
                    count++;
                }
            }
            
            
            
        }
        if(count==cf) return ans;
        else return -1;
        
        
        
    }
};