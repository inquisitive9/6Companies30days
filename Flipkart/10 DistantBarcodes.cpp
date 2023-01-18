class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>> pq;
        if(barcodes.size() == 0 || barcodes.size() == 1) {
            return barcodes;
        }
        map<int,int> mp;
        for(auto it:barcodes) {
            mp[it]++;
        }
        for(auto it:mp) {
            pq.push({it.second,it.first});
        }

        vector<int> res;
        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            res.push_back(f.second);
            if(pq.empty()) break;
            auto s = pq.top();
            pq.pop();
            res.push_back(s.second);
            if(f.first-1 != 0)
            pq.push({f.first-1,f.second});
            if(s.first-1 != 0)
            pq.push({s.first-1,s.second});
        }
        return res;
    }
};
