//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool solver(int index,vector<int>adj[],vector<int>&vis){
        queue<pair<int,int>>que;
        que.push({index,-1});
        vis[index]=1;
        while(!que.empty()){
            int ele=que.front().first;
            int parent=que.front().second;
        
            que.pop();
            for(auto it:adj[ele]){
                if(!vis[it]){
                    vis[it]=1;
                    que.push({it,ele});
                }else{
                    if(it!=parent)return true;
                }
            }
        }
        return false;
        
        
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // queue<pair<int,int>>que;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(solver(i,adj,vis)==true)return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends