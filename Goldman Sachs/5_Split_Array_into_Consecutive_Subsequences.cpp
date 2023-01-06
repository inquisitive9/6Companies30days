class Solution {
public:
bool isPossible(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return false;
    map<int, int> mp;
    for (auto it : nums)
    {
        mp[it]++;
    }
    map<int, int> req;
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        if (mp[num] == 0)
            continue;
        if(req[num] > 0 ) {
            req[num]--;
            mp[num]--;
            req[num+1]++;
        }
        else if (mp[num + 1] > 0 && mp[num + 2] > 0)
        {
            mp[num + 1]--;
            mp[num + 2]--;
            mp[num]--;
            req[num + 3]++;
        }
        else {
            return false;
        }
    }
    return true;
}

};
