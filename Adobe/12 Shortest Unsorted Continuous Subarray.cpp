class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp;
        int n = nums.size();
        int mx = nums[0];
        int end = -1;
        for(int i = 1 ; i < nums.size() ;i++) {
            mx = max(mx,nums[i]);
            if(nums[i] < mx) {
                end = i;
            }
        }

        int mn = nums[nums.size()-1];
        int st = -1;
        for(int j = nums.size()-2 ; j >= 0 ;j--) {
            mn = min(nums[j],mn);
            if(nums[j] > mn) {
                st = j;
            }
        }
       if(end == -1 && st == -1)      {
           return 0;
       }
       return end-st+1;
    }
};
