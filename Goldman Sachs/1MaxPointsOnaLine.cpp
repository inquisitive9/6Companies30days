class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        int mxcnt = 1;
        for(int i = 0 ; i < n ; i++)    {
            double x1 = points[i][0];
            double y1 = points[i][1];
            for(int j = i + 1 ; j < n ; j++) {
                double x2 = points[j][0];
                double y2 = points[j][1];
                double m;
                if(x2-x1 == 0) {
                    m  = INT_MAX;
                }
                else
                 m = (y2-y1)/(x2-x1);
                int cnt = 2;
                for(int k = j+1 ; k < n ; k++) {
                    double x3 = points[k][0];
                    double y3 = points[k][1];
                    double m2;
                    if(x3-x2 == 0)      {
                        m2 = INT_MAX;
                    }
                    else {
                        m2 = (y3-y2)/(x3-x2);     
                    }
                    if(m2 == m) {
                        cnt++;
                    }
                    mxcnt = max(mxcnt,cnt);
                }
                mxcnt = max(mxcnt,cnt);
            }
        }
        return mxcnt;
    }

};
