class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int mn = INT_MAX;
        for(auto it:right) {
            mn = min(mn,it);
        }
        int mx = INT_MIN;
        for(auto it:left) {
            mx = max(mx,it);
        }
        return max(n-mn,mx);
    }
};
