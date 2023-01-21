class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(),special.end());
        int mx = max(special[0]-bottom,top-special.back());
        for(int i = 1 ; i < special.size() ;i++) {
            mx = max(mx,special[i]-special[i-1]-1);
        }
        return mx;
    }
};
