class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // int m=graph[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int nodes=graph[i][j];
                adj[nodes].push_back(i);
                
                
            }
        }
        int V=n;
        
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>toposort;
	    vector<int>ans;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0){
	            toposort.push(i);
	        }
	    }
	    while(!toposort.empty()){
	        ans.push_back(toposort.front());
	        for(auto it:adj[toposort.front()]){
	            indegree[it]--;
	            if(indegree[it]==0){
	                toposort.push(it);
	            }
	        }
	        toposort.pop();
	        
	    }
        sort(ans.begin(),ans.end());
	    return ans;
	    
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(graph[i][j]==1)
        //     }
        // }
        
    }
};