class Solution {
public:
 int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = n-1 ; i >= 0 ;i--) {
            for(int j = m-1 ; j >= 0 ; j--) {
                int cost = dungeon[i][j] ;
                if(i+1 < n && j+1 < m)  {
                    cost += max(dp[i+1][j],dp[i][j+1]);
                }
                else if(i+1 < n) {
                    cost += dp[i+1][j];
                }
                else if(j+1 < m) {
                    cost += dp[i][j+1];
                }
                cost = min(cost,0);
                dp[i][j] = cost;
            }
        }

        return abs(dp[0][0])+1;
    }
};
