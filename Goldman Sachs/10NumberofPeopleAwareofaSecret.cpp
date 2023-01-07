class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        long long nos = 0;
        dp[1] = 1;
        long long mod = (int)1e9+7;

        for(int i = 2 ; i <= n ; i++) {
            nos = (nos + (dp[max(0,i-delay)]-dp[max(0,i-forget)]) + mod)%mod;
            dp[i] = nos;
        }

        long long ans = 0 ;
        for(int i = max(0,n-forget+1) ; i <= n ;i++) {
            ans = (ans + dp[i])%mod;
        }
        
        return (int)ans;
    }
};
