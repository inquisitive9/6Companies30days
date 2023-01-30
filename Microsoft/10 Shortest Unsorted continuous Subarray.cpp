class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int st = -1 , end = -1;
        int mn = nums[n-1];
        int mx = nums[0];
        for(int i = 0 ; i < nums.size() ;i++) { 
            mx = max(mx,nums[i]);
            if(nums[i] < mx) {
                end = i;
            }
            mn = min(mn,nums[n-i-1]);
            if(nums[n-i-1] > mn) 
            st = n-i-1;
        }
        if(end == -1 && st == -1) return 0 ;
        return end-st+1;

    }
};
