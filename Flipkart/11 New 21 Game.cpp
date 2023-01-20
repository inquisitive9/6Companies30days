class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0 || n >= k+maxPts) {
            return 1;
        }

        double dp[n+1];
        memset(dp,0.0,sizeof(dp));
        dp[0] = 1.0;
        double res = 0.0;
        double runningSum = dp[0];
        for(int i = 1 ; i <= n ;i++) {
            dp[i] = runningSum/((double)maxPts);

            // Adding value to frontEnd of a runningSum
            if(i<k) {
                runningSum += dp[i];
            }
            else {
                res += dp[i];
            }
            if(i-maxPts >= 0) {
                runningSum -= dp[i-maxPts];
            }

        }
        
        return res;
    }
};
