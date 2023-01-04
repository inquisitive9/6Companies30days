class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        sort(nums.begin(),nums.end());
        vector<int> hash(nums.size());
        vector<int> pre(nums.size(),1);
        int mx = 1;
        int lastIdx = 0;
        for(int i = 0 ; i < n ;i++) {
            hash[i] = i;
            for(int prev = 0 ; prev < i ; prev++) {
                if((nums[i]%nums[prev] == 0) && pre[i] < pre[prev]+1) {
                    pre[i] = max(pre[i],pre[prev]+1);
                    hash[i] = prev;
                }
            }
            if(pre[i] > mx) {
                mx = pre[i];
                lastIdx = i;
            }
        }
        while(hash[lastIdx] != lastIdx) {
            res.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        res.push_back(nums[lastIdx]);
        return res;
    }
};
