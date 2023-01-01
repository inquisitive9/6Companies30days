class Solution {
public:

    void helper(vector<int> arr,vector<int>& temp,vector<vector<int>>& ans,
    int i,int k,int n) {
        if(k == 0 && n == 0) {
            ans.push_back(temp);
            return ;
        }
        if(k <= 0) return;

        if(i >= arr.size()) {
            return;
        }

        if(n-arr[i] >= 0)     {
            temp.push_back(arr[i]);
            helper(arr,temp,ans,i+1,k-1,n-arr[i]);
            temp.pop_back();
        }
        // not Take
        helper(arr,temp,ans,i+1,k,n);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res(9,0);
        for(int i = 0 ; i < 9 ;i++) res[i] = i+1;
        vector<int> temp;
        vector<vector<int>> ans;
        helper(res,temp,ans,0,k,n)   ;
        return ans;
    }

};
