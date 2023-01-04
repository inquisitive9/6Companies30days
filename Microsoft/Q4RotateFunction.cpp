class Solution {
public:
     int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long mx = INT_MIN;
        long long orig = 0;
        for(int i = 0 ; i < n ;i++) {
            sum  += nums[i];
            orig += i*nums[i];
        }
        for(int i = n-1 ; i >= 0 ;i--) {
            orig = orig + sum - nums[i]*n;
            mx = max(orig,mx);
        }
        return mx;
    }
};
