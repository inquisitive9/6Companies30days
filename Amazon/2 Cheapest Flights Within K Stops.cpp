class Solution {
public:
    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        int n = flights.size();
        vector<pair<int,int>> adj[V];
        for(int i = 0 ; i < n ; i++) {
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        vector<int> dist(V,1e9);
        dist[src] = 0;
        while(!q.empty()) {
            int n = q.size();
            // while(n--) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if(stops>k) continue;
            for(auto iter:adj[node]) {
                int adjNode = iter.first;
                int endDis = iter.second;
                if(iter.second + dis < dist[adjNode] && stops <= k) {
                    dist[adjNode] = iter.second + dis;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        //   } 
        }

        if(dist[dst] == 1e9) return -1;

        return dist[dst];

    }

};
