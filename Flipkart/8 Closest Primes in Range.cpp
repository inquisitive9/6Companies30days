class Solution {
public:
 vector<int> primeNum(int left,int n)
    {
        vector<bool> sieve(n+1,1);
        sieve[0] = 0 ;
        sieve[1] = 0;
        for(int i = 2 ; i*i <= n ; i++) {
            if(sieve[i]) {
                for(int j = i*i ; j <= n ; j+=i) {
                    sieve[j] = 0;
                }
            }
        }
        
        vector<int> res;
        for(int i = left ; i <= n ; i++) {
            if(sieve[i])res.push_back(i);
        }
        return res;   
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = primeNum(left,right) ;
        int mn = INT_MAX;
        vector<int> res(2);
        if(ans.size() < 2 ) {
            return {-1,-1};
        }
        for(int i = 0 ; i < ans.size()-1 ;i++) {
            if((ans[i+1] - ans[i]) < mn) {
                res[0] = ans[i];
                res[1] = ans[i+1];
                mn = ans[i+1] - ans[i];
            }
        }
        return res;
    }
};
