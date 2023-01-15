class Solution {
public:
    int findIntegers(int n) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for(int i = 2 ; i < 32 ;i++) {
            f[i] = f[i-1] + f[i-2];
        }

        int ans = 0 , k = 30 , prebit = 0;
        while(k >= 0) {
            if(n&(1<<k)) {
                ans += f[k];
                if(prebit) return ans;
                prebit = 1;
            }
            else {
                prebit = 0;
            }
            k--;
        }
        return ans+1;
    }
};
