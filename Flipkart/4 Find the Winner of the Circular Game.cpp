class Solution {
public:
    int helper(int idx,int k,int n,vector<int>& cir) {
        if(cir.size() == 1) {
            return cir[0];
        }
        int del = (idx+k-1)%cir.size();
        cir.erase(cir.begin()+del);
        return helper(del,k,n,cir);
    }
    int findTheWinner(int n, int k) {
        vector<int> res;
        for(int i = 0 ; i < n ;i++) {
            res.push_back(i+1);
        }
        return helper(0,k,n,res);
    }
};
