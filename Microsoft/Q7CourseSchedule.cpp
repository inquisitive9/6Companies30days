class Solution {
public:
    bool isCycle(int V,vector<int> adj[],vector<int>& vis,vector<int>& pathVis,int st) {
        vis[st] = 1;
        pathVis[st] = 1;
        for(auto i :adj[st]) {
            if(!vis[i]) {
                if(isCycle(V,adj,vis,pathVis,i))
                    return true;
            }
            else if(pathVis[i]) {
                return true;
            }
        }
        pathVis[st] = 0;
        return false;
    }
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(int i = 0 ; i < prerequisites.size() ; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        for(int i = 0 ; i < V ; i++) {
            if(!vis[i])
        if(isCycle(V,adj,vis,pathVis,i)) {
            return false;
        }
        }
        return true;
        
    }
};
