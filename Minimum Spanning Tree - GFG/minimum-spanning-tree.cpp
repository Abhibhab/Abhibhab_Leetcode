//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
    public:
    vector<int>size,par;
    DSU(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
        
    }
    int findpar(int node) {
        if (node == par[node])
            return node;
        return par[node] = findpar(par[node]);
    }
    void unisize(int x,int y){
        int u=findpar(x);
        int v=findpar(y);
        if(u==v)return;
        if(size[u]>size[v]){
            par[v]=u;
            size[v]+=size[u];
        }else{
            par[v]=u;
            size[u]+=size[v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
     vector<pair<int,pair<int,int>>>edges;
     for(int i=0;i<V;i++){
         for(auto it:adj[i]){
         int node=i;
         int nodeto=it[0];
         int weight=it[1];
         edges.push_back({weight,{node,nodeto}});
         }
     }
     DSU ds(V);
     sort(edges.begin(),edges.end());
     int ans=0;
     for(auto it:edges){
         int weight=it.first;
         int node=it.second.first;
         int nodeto=it.second.second;
         if(ds.findpar(nodeto)!=ds.findpar(node)){
             ans+=weight;
             ds.unisize(node,nodeto);
         }
     }
     return ans;
     
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends