class Solution {
public:
    string longestPrefix(string s) {
        long int hash1 = 0 , hash2 = 0; // hash1 for forward and hash2 for reverse from end
        int M = 1e9 + 7 , p = 37, n = s.length();
        long int pow = 1;
        string ans = "", t = "";
        for(int i=0;i<n-1;i++){
            t += s[i];
            hash1 += (s[i] - 'a')*pow;
            hash2 *= p;
            hash2 += (s[n-1-i] - 'a');
            pow *= p;
            pow %= M;
            hash1 %= M;
            hash2 %= M;
            if(hash1 == hash2) ans = t;
        }
        return ans;
    }
};
