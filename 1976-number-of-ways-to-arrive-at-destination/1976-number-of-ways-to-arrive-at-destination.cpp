class Solution {
public:
      const long long mod=1e9+7;
    long long INF = 1e15;
    int countPaths(int n, vector<vector<int>>& roads) {
      
        vector<pair<long long,long long>>adj[n+1];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>dist(n,INF),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            long long dis=it.first;
            long long node=it.second;
            pq.pop();
            for(auto it1:adj[node]){
                long long newnode=it1.first;
                long long newdis=it1.second;
                if(dis+newdis<dist[newnode]){
                    dist[newnode]=(dis+newdis);
                    ways[newnode]=ways[node];
                    pq.push({dist[newnode],newnode});
                    
                }else if(dis+newdis==dist[newnode]){
                    ways[newnode]=(ways[newnode]+ways[node])%mod;
                }
            
            }
        }
        // if(dist[n-1]==1e9)return 0;
        return ways[n-1];
        
    }
};