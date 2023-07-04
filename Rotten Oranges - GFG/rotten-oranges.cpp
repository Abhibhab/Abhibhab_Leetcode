//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code hereq
        int good_apples=0;
        queue<pair<int,int>>que;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)good_apples++;
                if(grid[i][j]==2)que.push({i,j});
            }
        }
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        int cnt=0;
        int days=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                auto ele=que.front();
                int x=ele.first,y=ele.second;
                que.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1)continue;
                    cnt++;
                    grid[nx][ny]=2;
                    que.push({nx,ny});
                    
                }
            }
            if(!que.empty())days++;
        }
        if(good_apples==cnt)return days;
        else return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends