class Solution {
public:
 int maxCoins(vector<int>& piles) {
      multiset<int> ms;
      int n = piles.size();
      for(int i = 0 ; i < n ;i++) {
          ms.insert(piles[i]);
      }
      int res = 0;
      while(ms.size() > 0) {
          ms.erase(ms.lower_bound(*ms.rbegin()));
          res = res + *ms.rbegin();
          ms.erase(ms.lower_bound(*ms.rbegin()));
          ms.erase(ms.lower_bound(*ms.begin()));
      }
        return res;
    }
};
