//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solver(int index,int col,vector<int>adj[],vector<int>&vis,vector<int>&colour){
        vis[index]=1;
        colour[index]=col;
        for(auto it:adj[index]){
            if(vis[it]==0){
                if(solver(it,!col,adj,vis,colour)==false)return false;
            }else{
                if(colour[it]==col)return  false;
            }
        }
        return true;
        
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,0),colour(V,-1);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(solver(i,0,adj,vis,colour)==false)return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends