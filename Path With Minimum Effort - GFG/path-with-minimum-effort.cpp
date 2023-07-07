//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
         priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0,{0,0}});
          int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while(pq.size()){
            auto ele=pq.top();
            pq.pop();
            int dif=ele.first;
            int x=ele.second.first;
            int y=ele.second.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
               
                if(nx>=0 && ny>=0 && nx<n && ny<m ){
                     int mamla=max(dif,abs(heights[x][y]-heights[nx][ny]));
                     if(mamla<dist[nx][ny]){
                    dist[nx][ny]=mamla;
                    pq.push({mamla,{nx,ny}});
                     }
        }
    }
        }
        if(dis)
        return dist[n-1][m-1];
    }
    
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends