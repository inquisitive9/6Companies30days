class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> mp;
        int n = cards.size();
        int mini = INT_MAX;
        for(int i = 0 ; i < n ;i++) {
            if(mp.count(cards[i])) {
                mini = min(mini,i-mp[cards[i]]+1);
            }
            mp[cards[i]] = i;
        }
        if(mini == INT_MAX) {
            return -1;
        }
        return mini;
    }
};
