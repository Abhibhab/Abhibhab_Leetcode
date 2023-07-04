//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),0));
	    vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
	    queue<pair<int,pair<int,int>>>que;
	    int indx[4]={-1,1,0,0};
	    int indy[4]={0,0,-1,1};
	    int n=grid.size();
	    int m=grid[0].size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                que.push({i,{j,0}});
	                vis[i][j]=1;
	            }
	        }
	    }
	   
	    while(!que.empty()){
	        auto it=que.front();
	        int x=it.first;
	        int y=it.second.first;
	        int level=it.second.second;
	        que.pop();
	        ans[x][y]=level;
	        for(int i=0;i<4;i++){
	            int nx=x+indx[i];
	            int ny=y+indy[i];
	            if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny]==1)continue;
	            que.push({nx,{ny,level+1}});
	            vis[nx][ny]=1;
	        }
	        
	        
	    }
	    return ans;
	    
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends