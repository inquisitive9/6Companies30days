class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.size();
        queue<int> q1;
        queue<int> q2;
        for(int i = 0 ; i < n ;i++) {
            if(s[i] == 'R') q1.push(i);
            else q2.push(i);
        }   
        while(!q1.empty() && !q2.empty()) {
            int r = q1.front();
            int l = q2.front();
            q1.pop();
            q2.pop();
            if(r<l) {
                q1.push(r+n);
            }
            else 
            q2.push(l+n);
        }
        return q1.size() > q2.size() ? "Radiant" : "Dire";
    }
};
