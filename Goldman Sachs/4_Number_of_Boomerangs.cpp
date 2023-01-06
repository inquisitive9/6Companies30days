class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
            long long n = points.size()  ;
            long long cnt = 0;
            sort(points.begin(),points.end());
            map<long long ,int> mp;
           // int cnt = 0;
            for(int i = 0 ; i < n ;i++) {
                long long x1 = points[i][0];
                long long y1 = points[i][1];
                map<long long ,int> mp;
                for(int j = 0 ; j < n ;j++) {
                    if(j==i) continue;
                    long long x2 = points[j][0];
                    long long y2 = points[j][1];
                    long long dist1 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                    mp[dist1]++;
                }
                for(auto it : mp) {
                    if(it.second >= 2) {
                        cnt += it.second*(it.second-1);
                    }
                }
            }
            return (int)cnt;
    }

};
