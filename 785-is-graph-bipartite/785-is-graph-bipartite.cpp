class Solution {
public:
    bool dfs(vector<vector<int>>&graph,int node,vector<int>&vis,vector<int>&colour,int colourcur){
        vis[node]=1;
        colour[node]=colourcur;
        for(int i=0;i<graph[node].size();i++){
            int cur=graph[node][i];
            if(vis[cur]==0 && colour[cur]==-1){
                if(dfs(graph,cur,vis,colour,!colourcur)==false){
                    return false;
                }
            }else{
                if(colour[cur]==colour[node])return false;
            }
        }
        return true;
        
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0),colour(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==0){
                if(dfs(graph,i,vis,colour,0)==false)return false;
            }
        }
        return true;
        
    }
};