class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt(3,0);
        int j = 0;
        int n = s.size();
        int res = 0;
        for(int i = 0 ; i < n ;i++) {
            cnt[s[i]-'a']++;
            while(cnt[0] && cnt[1] && cnt[2]) {
                cnt[s[j++]-'a']--;
            }
            res += j;
        }
        return res;
    }
};
