class Solution {
public:
   
    void dfs(vector<vector<char>>&board,int row,int col,vector<vector<int>>&vis){
         int drow[]={0,1,0,-1};
    int dcol[]={-1,0,1,0};
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                dfs(board,nrow,ncol,vis);
            }
        }
        
        
        
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(vis[i][j]==0 && board[i][j]=='O'){
                    dfs(board,i,j,vis);
                    }
                }
            }
        }
//         for(int j=0;j<m;j++){
//             if(vis[0][j]==0 && board[0][j]=='O'){
//                 dfs(board,0,j,vis);
                
//             }
//             if(vis[n-1][j]==0 && board[n-1][j]=='O'){
//                 dfs(board,n-1,j,vis);
//             }
//         }
//          for(int j=0;j<n;j++){
//             if(vis[j][0]==0 && board[j][0]=='O'){
//                 dfs(board,j,0,vis);
                
//             }
//             if(vis[j][m-1]==0 && board[j][m-1]=='O'){
//                 dfs(board,j,m-1,vis);
//             }
//         }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]==0 && board[i][j]=='O'){
                        board[i][j]='X';
                    }
                }
            }
        }
        
    
};