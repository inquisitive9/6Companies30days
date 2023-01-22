class Solution {
public:
   int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int cnt = 0;
        map<int,int> mp;
        int mx = 0;
        int j = 0;
        for(int i = 0 ; i < n ;i++) {
            if(!mp.count(fruits[i])) {
                cnt++;
            }
            mp[fruits[i]]++;
            while(cnt > 2) {
                mp[fruits[j]]--;
                if(mp[fruits[j]] == 0) {
                    mp.erase(fruits[j]);
                    cnt--;
                }
                j++;
            }
            mx = max(mx,i-j+1);
        }
        return mx;
    }
 
};
