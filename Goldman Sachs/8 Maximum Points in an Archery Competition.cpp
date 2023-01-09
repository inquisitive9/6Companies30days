class Solution {
public:
int mx = 0;
vector<int> ans;
    void helper(int n,int i,int sc,vector<int>& aliceArrows,vector<int>& bobScore) {    
                if(i < 0 || n <= 0) {
            if(sc > mx) {
                mx = sc;
                ans.clear();
                if(n > 0) {
                    bobScore[0] += n;
                }
                ans = bobScore;
            }
            return;
        }

       // TAKE 
       if(n > aliceArrows[i]) {
            bobScore[i] = aliceArrows[i]+1;
            helper(n-aliceArrows[i]-1,i-1,sc+i,aliceArrows,bobScore);
            bobScore[i] = 0;
       }
       helper(n,i-1,sc,aliceArrows,bobScore);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bob(12,0);
        helper(numArrows,11,0,aliceArrows,bob);
        return ans;
    }

};
