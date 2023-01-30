const int INF = 1e9+1;

class Solution {

    vector<vector<int>> g;
    vector<int> val;
    vector<int> parent;
    vector<int> best_cost_till_leaf;
    
    void CalculateParent (int root) {
        for (auto child : g[root]) {
            if (child == parent[root]) continue;
            parent[child] = root;
            CalculateParent (child);
        }
    }
    
    void MaxPathToLeaf (int root) {
        int& cost = best_cost_till_leaf[root];
        cost = -INF;
        int child_count = 0;
        
        for (auto child : g[root]) {
            if (child == parent[root]) continue;
            
            child_count ++;
            MaxPathToLeaf (child);
            cost = max (cost, best_cost_till_leaf[child]);
        }
        
        if (child_count == 0) cost = val[root];
        else cost += val[root];
    }
    
    int FindBestExceptSpecificChild (int root, int child_to_skip) {
        int result = -INF;
        int child_count = 0;
        
        for (auto child : g[root]) {
            if (child == parent[root]) continue;
            
            child_count ++;
            if (child == child_to_skip) continue;
            
            result = max (result, best_cost_till_leaf[child]);
        }
        
        if (child_count == 0) return 0;
        return result;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        g.clear(), parent.clear(), val.clear(), best_cost_till_leaf.clear();
        int n = amount.size();
        g.resize(n), parent.resize(n), val.resize(n), best_cost_till_leaf.resize(n);
        
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        val = amount;
        
        parent[0] = -1;
        CalculateParent (0);
        MaxPathToLeaf (0);
        
        vector<int> path_of_bob;
        while (bob != -1) {
            path_of_bob.push_back(bob);
            bob = parent[bob];
        }
        reverse (path_of_bob.begin(), path_of_bob.end());
        
        // for (auto i: path_of_bob) cout << i << " "; cout << endl;
        // for (auto i : best_cost_till_leaf) cout << i << " "; cout << endl;
        
        int result = -INF;
        int bob_path_length = path_of_bob.size();
        
        for (int ind = 0, cost_till_now = 0; ind < bob_path_length; ind ++) {
            bool is_alice_first = (ind < bob_path_length-1-ind);
            bool is_same_arrival = (ind == bob_path_length-1-ind);
            
            if (is_alice_first)  cost_till_now += val[path_of_bob[ind]];
            if (is_same_arrival) cost_till_now += val[path_of_bob[ind]] / 2;
            
            result = max (
                result, 
                cost_till_now + FindBestExceptSpecificChild (path_of_bob[ind], ind+1 < bob_path_length? path_of_bob[ind+1] : -1)
            );
        }
        return result;
    }
};
