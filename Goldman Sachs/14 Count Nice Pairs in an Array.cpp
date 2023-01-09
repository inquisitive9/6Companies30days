class Solution {
public:
    int revNum(int n) {
        int rev = 0;
        while(n>0) {
            rev = rev*10+n%10;
            n/=10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> revers(nums.size(),0) ;
        for(int i = 0 ; i < n ;i++) {
            revers[i] = revNum(nums[i]);
        }
        long long cnt = 0;
        long long mod = (int)1e9+7;
        map<int,int> mp;
        for(int i = 0 ; i < n ;i++) {
            mp[nums[i]-revers[i]]++;
        }
        for(auto it:mp) {
            if(it.second > 1) {
                long long n = it.second;
                cnt = (cnt + (n*(n-1)/2)%mod)%mod;
            }
        }
        return cnt;
    }
};
