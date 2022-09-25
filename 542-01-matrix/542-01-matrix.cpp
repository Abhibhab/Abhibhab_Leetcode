class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>bfs;
        int cf=0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    bfs.push({{i,j},0});
                    vis[i][j]=0;
                    
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
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==-1){
                    vis[nrow][ncol]=vis[row][col]+1;
                    bfs.push({{nrow,ncol},level+1});
                    
                    count++;
                }
            }
            
            
            
        }
      return vis;
        
//         int m=mat.size();
//         int n=mat[0].size();
//         vector<vector<int>> fin(m,vector<int>(n,-1));
//         queue<pair<int,int>> q;

            
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==0){
//                     q.push({i,j});
//                     fin[i][j]=0;
//                 }
//             }
//         }
        
//         int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
//         int res=0;
            
//             while(!q.empty()){
                
//                 int r=q.front().first;
//                 int c=q.front().second;
//                 q.pop();
                
//                 for(auto dir:dirs){
//                     int sr=r+dir[0];
//                     int sc=c+dir[1];
//                     if(sr>=0 && sc>=0 && sr<m && sc<n && fin[sr][sc]==-1){
//                         fin[sr][sc]=fin[r][c]+1;
//                         q.push({sr,sc});
//                     }
//                 }
                
//             }
        
//         return fin;
//         int m=mat.size();
//         int n=mat[0].size();
//         queue<pair<int,int>>bfs;
//         vector<vector<int>>vis(m,vector<int>(n,-1));
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(mat[i][j]==0){
//                     vis[i][j]=0;
//                     bfs.push({i,j});
//                 }
//             }
//         }
//         int drow[]={-1,0,+1,0};
//         int dcol[]={0,+1,0,-1};
//         while(!bfs.empty()){
//            int row=bfs.front().first;
//             int col=bfs.front().second;
//             bfs.pop();
//             for(int i=0;i<4;i++){
//                 int nrow=row+drow[i];
//                 int ncol=col+dcol[i];
//                 if(vis[nrow][ncol]==-1 && nrow<m && ncol<n && nrow>=0 && ncol>=0){
//                     vis[nrow][ncol]=vis[row][col]+1;
//                     bfs.push({nrow,ncol});
//                 }
//             }
//         }
//         return vis;
        
        
//         int n=mat.size();
//         int m=mat[0].size();
//         queue<pair<pair<int,int>,int>>bfs;
//         vector<vector<int>>vis(n,vector<int>(m,-1));
//         // vector<vector<int>>ans(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(mat[i][j]==0){
//                     bfs.push({{i,j},0});  
//                     vis[i][j]=0;
//                 }
                
//             }
//         }
//         int drow[4]={1,0,-1,0};
//         int dcol[4]={0,1,0,-1};
//         while(!bfs.empty()){
//             int row=bfs.front().first.first;
//             int col=bfs.front().first.second;
//             int level=bfs.front().second;
//             // vis[row][col]=level;
//             bfs.pop();
//             for(int i=0;i<4;i++){
//                 int nrow=row+drow[i];
//                 int ncol=col+dcol[i];
//                 if(vis[nrow][ncol]==-1 && nrow>=0 && ncol>=0 && ncol<m && nrow<n){
//                     vis[nrow][ncol]=level+1;
//                     bfs.push({{nrow,ncol},level+1});
//                 }
//             }
            
            
//         }
//         return vis;
        
    }
};