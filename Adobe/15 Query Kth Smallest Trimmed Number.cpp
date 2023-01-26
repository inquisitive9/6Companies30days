class Solution {
public:
vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
{
    vector<int> res;
    // position of digit
    for(auto& q:queries) {
        vector<pair<string,int>> temp;
        for(int j = 0 ; j < nums.size() ;j++) {
            temp.push_back({(nums[j].substr(nums[j].size()-q[1])),j});
        }
        sort(temp.begin(),temp.end());
        res.push_back(temp[q[0]-1].second);
    }

    return res;
}

};
