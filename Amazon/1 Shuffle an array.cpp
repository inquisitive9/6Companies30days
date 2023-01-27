class Solution {
public:
    vector<int> arr;
    vector<int> temparr;
    Solution(vector<int>& nums) {
        for(auto it:nums) {
            arr.push_back(it);
            temparr.push_back(it);
        }
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
       for(int i = arr.size()-1 ; i > 0 ;i--) {
           int j = rand()%(i+1);
           swap(temparr[i],temparr[j]);
       }
       return temparr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
