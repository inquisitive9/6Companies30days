class Solution {
public:
    int rowoffset[8] = {-2,-2,-1,-1,2,2,1,1};
    int coloffset[8] = {1,-1,2,-2,1,-1,2,-2};
    bool isValid(int n,int r,int c) {
        if(r<0 || c<0 || r>=n || c>= n) return false;
        return true;
    }
    double helper(int n,int k,int r,int c,map<string,double>& mp) {
        if(!isValid(n,r,c)) return 0;
        if (k == 0) return 1;
        string code = to_string(r) + " " + to_string(c) + " " + to_string(k);
        if(mp.count(code)) return mp[code];
        double prob = 0.0;
        for(int i = 0 ; i < 8 ; i++) {
            prob += (helper(n,k-1,r+rowoffset[i],c+coloffset[i],mp)/8.0);
        }
        return mp[code] = prob;
    }
    double knightProbability(int n, int k, int row, int column) {
            map<string,double> mp;
            return helper(n,k,row,column,mp);
    }
};
