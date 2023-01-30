class Solution {
public:
struct comp {
    bool operator()(pair<int,string>& p1,pair<int,string>& p2) {
    if(p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
   }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto word:words) {
            mp[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        for(auto it : mp) {
            int freq = it.second;
            string word = it.first;
            pq.push({freq,word});
            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res(k);
        while(!pq.empty()) {
            res[--k] = pq.top().second;
            pq.pop();
        }
        return res;
    }

};
