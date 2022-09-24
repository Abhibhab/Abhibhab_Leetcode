class Solution {
public:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,-1,0,1};
    void dfs(vector<vector<int>>&image,int sr,int sc,int color,vector<vector<int>>&vis,int n,int m,int first){
        vis[sr][sc]=1;
        image[sr][sc]=color;
        for(int i=0;i<4;i++){
            int nxtrow=sr+drow[i];
            int nxtcol=sc+dcol[i];
            if(nxtrow>=0 && nxtrow<n && nxtcol>=0 && nxtcol<m && image[nxtrow][nxtcol]==first && vis[nxtrow][nxtcol]==0){
                dfs(image,nxtrow,nxtcol,color,vis,n,m,first);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int first=image[sr][sc];
        int n=image.size(),m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(image,sr,sc,color,vis,n,m,first);
        return image;
        
        
    }
};