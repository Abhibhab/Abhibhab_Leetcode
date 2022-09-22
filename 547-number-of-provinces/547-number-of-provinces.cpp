class Solution {
public:
     void dfs(vector<vector<int>>&adj,int node,vector<bool>&vis){
      vis[node]=true;
     for(int i=0;i<adj[node].size();i++){
       
         if(adj[node][i]==1 && vis[i]==false){
             dfs(adj,i,vis);
             
         }
     }
      
  }
//     int numProvinces(vector<vector<int>> adj, int V) {
//         // code here
//         vector<bool>vis(V,false);
//         int count=0;
//         for(int i=0;i<V;i++){
//             if(vis[i]==false){
//                 count++;
//                 dfs(adj,V,i,vis);
//             }
            
//         }
//         return count;
        
        
        
//     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>vis(isConnected.size(),false);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
            count++;
            if(!vis[i]) dfs(isConnected,i,vis);
            }
        }
        return count;
    }
};