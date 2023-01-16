class Solution {
public:
    bool helper(vector<int>& nums,vector<int>& vis,int idx,int curSum,int& subsetSum,int k) {

        if(k == 1) {
            return true;
        }

        if(idx >= nums.size()) return false;

        if(curSum == subsetSum) {
            return helper(nums,vis,0,0,subsetSum,k-1);
        }

        for(int i = idx ; i < nums.size() ;i++) {
            if(vis[i] || curSum+nums[i] > subsetSum) continue;
            vis[i] = 1;
            if(helper(nums,vis,i+1,curSum+nums[i],subsetSum,k)) {
                return true;
            }
            vis[i] = 0;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);

        if (nums.size() < k || sum % k) return false;
        int req = sum/k;
        vector<int> vis(nums.size(),0);
        return helper(nums,vis,0,0,req,k); // nums,idx,curSum,SubsetSum,k
    }
};
