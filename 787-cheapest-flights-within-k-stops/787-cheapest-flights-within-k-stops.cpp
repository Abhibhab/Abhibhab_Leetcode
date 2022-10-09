class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto it=q.top();
            int node=it.second.first;
            int stop=it.first;
            int dis=it.second.second;
            q.pop();
            if(stop>k)continue;
            for(auto it1:adj[node]){
                int adjnode=it1.first;
                int adjdist=it1.second;
                if(dis+adjdist<dist[adjnode] && stop<=k){
                    dist[adjnode]=dis+adjdist;
                    q.push({stop+1,{adjnode,dis+adjdist}});
                }
                
            }
        }
        if(dist[dst]==1e9)return -1;
        else return dist[dst];
        
        
        
        
    }
};