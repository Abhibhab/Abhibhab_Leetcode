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
   vector<int>inorder(V,0);
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            inorder[it]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(inorder[i]==0)q.push(i);
	    }
	    vector<int>ans;
	    
	    while(!q.empty()){
	        auto ele=q.front();
	        ans.push_back(ele);
	        q.pop();
	        for(auto it:adj[ele]){
	            inorder[it]--;
	            if(inorder[it]==0){
	                q.push(it);
	            }
	        }
	    }
	    return ans.size()!=V;
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