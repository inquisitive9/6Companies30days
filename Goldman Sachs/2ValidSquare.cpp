class Solution {
public:
long long dist(vector<int>& p1, vector<int>& p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}
 bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // p1p3 || p2p4
        set<pair<int,int>> s;
        s.insert({p1[0],p1[1]});
        s.insert({p2[0],p2[1]});
        s.insert({p3[0],p3[1]});
        s.insert({p4[0],p4[1]});
        if(s.size() != 4)  return false;
       unordered_set<long long> st;
       st.insert(dist(p1 ,p2)),st.insert(dist(p2,p3)),st.insert(dist(p3,p4)),st.insert(dist(p4,p1)),st.insert(dist(p1,p3)),st.insert(dist(p2,p4));
       if(st.size() == 2) {
           return true;
       }
       return false;
    }

};
