class Solution {
public:
   int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1] ;
        for(int i = 0 ; i < times.size() ;i++) {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        int mxtime = 0;
        pq.push({0,k});
        while(!pq.empty()) {
            int N = pq.size();
            while(N--) {
                auto p = pq.top();
                pq.pop();
                int node = p.second;
                int tm = p.first;
                for(auto ele:adj[node]) {
                    int neightbourNode = ele.first;
                    int neighbourtime = ele.second;
                    if(dist[neightbourNode] > tm + neighbourtime) {
                        dist[neightbourNode] = tm + neighbourtime;
                        pq.push({dist[neightbourNode],neightbourNode});
                    }
                }
            }
        }
        for(int i = 1 ; i <= n ;i++) {
            mxtime = max(mxtime,dist[i]);
            if( dist[i] == INT_MAX) return -1;
        }
        return mxtime;
    }

};
