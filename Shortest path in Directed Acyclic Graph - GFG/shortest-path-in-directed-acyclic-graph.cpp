//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void topoSort(int node, vector < pair < int, int >> adj[],
      int vis[], stack < int > & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            int node=edges[i][0];
            int to=edges[i][1];
            int weight=edges[i][2];
            adj[node].push_back({to,weight});
            }
            vector<int>dist(N,1e9);
            stack<int>st;
            int vis[N]={0};
            dist[0]=0;
            for(int i=0;i<N;i++){
                if(!vis[i])
            topoSort(i,adj,vis,st);
            }
            while(!st.empty()){
                auto ele=st.top();
                st.pop();
                for(auto it:adj[ele]){
                    int node_to=it.first;
                    int paisa=it.second;
                    if(dist[ele]+paisa<dist[node_to]){
                        dist[node_to]=dist[ele]+paisa;
                    }
                }
                
            }
            for(int i=0;i<N;i++){
            if(dist[i]==1e9)dist[i]=-1;
            }
            return dist;
                    
            
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends