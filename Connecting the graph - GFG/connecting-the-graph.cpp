//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
       DSU d(n);
       int count=0;
       for(int i=0;i<edge.size();i++){
           int node=edge[i][0];
           int nodeto=edge[i][1];
           if(d.findpar(node)!=d.findpar(nodeto)){
               d.unisize(node,nodeto);
               
           }else if(d.findpar(node)==d.findpar(nodeto)){
               count++;
               
           }
       }
       int compo=0;
       for(int i=0;i<n;i++){
           if(d.findpar(i)==i)compo++;
           
       }
       int ans=compo-1;
       if(ans<=count)return ans;
       return -1;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends