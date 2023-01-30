class Solution {
public:
  // d : position , k : num of steps
  int mod = (int)1e9+7;
    int helper(int curr,int k,int dest,int src,vector<vector<int>>& dp) {

        if(k==0) {
            if(curr == dest) {
                return 1;
            }
            return 0;
        }
        if(dp[curr+1000][k] != -1) return dp[curr+1000][k];
        int left = helper(curr-1,k-1,dest,src,dp)%mod;
        int right = helper(curr+1,k-1,dest,src,dp)%mod;

        return dp[curr+1000][k]  = (left+right)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3002,vector<int>(1001,-1));
        return helper(startPos,k,endPos,0,dp);
    }
};
