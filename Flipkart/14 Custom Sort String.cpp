class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        int m = s.size();
        map<char,int> mp;
        for(auto it:s) {
            mp[it]++;
        }
        string res = "";
        for(auto it:order) {
            while(mp[it] > 0) {
                res += it;
                mp[it]--;
            }
            if(mp.count(it)) {
                mp.erase(it);
            }
        }

        for(int i = 0 ; i < s.size() ;i++) {
            if(mp.count(s[i])) {
                res += s[i];
            }
        }

        return res;

    }
};
