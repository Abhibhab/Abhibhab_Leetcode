//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
int inx[4]={0,0,-1,1};
int iny[4]={-1,1,0,0};
void solver(int x,int y,vector<vector<char>>mat,vector<vector<int>>&vis,int n,int m){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+inx[i];
        int ny=y+iny[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0 && mat[nx][ny]=='O')solver(nx,ny,mat,vis,n,m);
    }
    
}
public:
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>>ans=mat;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && mat[i][0]=='O')solver(i,0,mat,vis,n,m);
            if(vis[i][m-1]==0 && mat[i][m-1]=='O')solver(i,m-1,mat,vis,n,m);
            
        }
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 && mat[0][i]=='O')solver(0,i,mat,vis,n,m);
            if(vis[n-1][i]==0 && mat[n-1][i]=='O')solver(n-1,i,mat,vis,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' and vis[i][j]==0)ans[i][j]='X';
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends