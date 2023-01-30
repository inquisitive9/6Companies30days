class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        unordered_map<char,vector<int>> mp;
        for(int i = 0 ; i < n ;i++) {
            mp[s[i]].push_back(i);
        }   
        int cnt = 0;
        for(auto curr:words) {
            int n = curr.size();
            int prev = -1;
            for(int j = 0 ; j < curr.size() ;j++) {
                    if(!mp.count(curr[j])) break;
                    auto it = upper_bound(mp[curr[j]].begin(),mp[curr[j]].end(),prev);
                    if(it == mp[curr[j]].end()) {
                      break;
                    }                
                    prev = *it;
                    if(j == curr.size()-1) {
                      cnt++;
                    }
            }
        }
        return cnt;
    }
};
