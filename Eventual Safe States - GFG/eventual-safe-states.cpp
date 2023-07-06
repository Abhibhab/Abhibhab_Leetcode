//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool solver(int index,vector<int>adj[],vector<int>&vis ,vector<int>&pathvis,vector<int>&safe){
      vis[index]=1;
      pathvis[index]=1;
      for(auto it:adj[index]){
          if(!vis[it]){
             if( solver(it,adj,vis,pathvis,safe)==true)return true;
          }else{
              if(pathvis[it]==1)return true;
          }
      }
      safe.push_back(index);
      pathvis[index]=0;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0),safe,pathvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
            solver(i,adj,vis,pathvis,safe);
        }
        sort(safe.begin(),safe.end());
        return safe;
        
        
        vector<int>rev[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
               rev[it].push_back(i);
            }
        }
        vector<int>inorder(V,0);
        for(int i=0;i<V;i++){
            for(auto it:rev[i])inorder[it]++;
        }
        queue<int>que;
        for(int i=0;i<V;i++){
            if(inorder[i]==0)que.push(i);
        }
        vector<int>ans;
        while(!que.empty()){
            int ele=que.front();
            que.pop();
            ans.push_back(ele);
            for(auto it:rev[ele]){
                inorder[it]--;
                if(inorder[it]==0)que.push(it);
            }
            
        }
        // sort(ans.begin(),ans.end());
        // return ans;
        
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends