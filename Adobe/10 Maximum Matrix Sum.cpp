class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& arr) {
        int mn = INT_MAX;
        long long sum = 0;
        int cnt = 0;
        int n = arr.size();
        int m = arr[0].size();
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ;j++) {
                if(arr[i][j] < 0 ) {
                    mn = min(mn,-1*arr[i][j]);
                    sum += (-1*arr[i][j]);
                    cnt++;
                }
                else  {
                     mn = min(mn,arr[i][j]);
                    sum += (arr[i][j]);
                }
            }
        }

        if(cnt%2 == 0) return sum;
        return sum-2*mn;

    }
};
