class Solution {
public:
      int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size() ;

        priority_queue< pair<int,int>,vector<pair<int,int>>,greater< pair<int,int> > > pqcap;
        priority_queue< pair<int,int> > pqProf;

        for(int i = 0  ; i < n ; i++) {
             pqcap.push({capital[i],profits[i]});
        }

        while(k--) {
            while(!pqcap.empty() && pqcap.top().first <= w) {
                pqProf.push({pqcap.top().second,pqcap.top().first});
                pqcap.pop();
            }
            if(pqProf.empty()) break;
            w += pqProf.top().first;
            pqProf.pop();
        }
        return w;
    }

  
};
