//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool solver(int index,vector<int>adj[],vector<int>&vis ,vector<int>&pathvis){
      vis[index]=1;
      pathvis[index]=1;
      for(auto it:adj[index]){
          if(!vis[it]){
             if( solver(it,adj,vis,pathvis)==true)return true;
          }else{
              if(pathvis[it]==1)return true;
          }
      }
      pathvis[index]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0),pathvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(solver(i,adj,vis,pathvis)==true)return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends