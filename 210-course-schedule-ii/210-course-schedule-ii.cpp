class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
         vector<int>adj[numCourses];
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>degre(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                degre[it]++;
            }
        }
        queue<int>topo;
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(degre[i]==0){
                topo.push(i);   
            }
        }
        while(!topo.empty()){
            ans.push_back(topo.front());
            for(auto it:adj[topo.front()]){
                degre[it]--;
                if(degre[it]==0) topo.push(it);
            }
            
            
            topo.pop();
            
                
        }
        // return ans.size()==numCourses;
        if(ans.size()==numCourses){
            return ans;
        }else{
            return {};
        }
        
        
        
    }
};