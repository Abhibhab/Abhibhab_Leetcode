class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int ans=0;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        dist[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int newr=row+drow[i];
                int newc=col+dcol[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int neweffort=max(dis,abs(heights[row][col]-heights[newr][newc]));
                    if(neweffort<dist[newr][newc]){
                        dist[newr][newc]=neweffort;
                        pq.push({neweffort,{newr,newc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
        
    }
};