class Solution {

    

public:

        int M;
    vector<int> ST;
    void update(int i, int val = 1) {
        i += M;
        ST[i] += val;
        while(i > 1) {
            i /= 2;
            ST[i] = ST[2*i] + ST[2*i+1];
        }
    }
    int getSum(int l, int r) {
        int res = 0;
        for (l += M, r += M; l < r; l /= 2, r /= 2) {
            if (l % 2) {
                res += ST[l++];
            }
            if (r % 2) {
                res += ST[--r];
            }
        }
        return res;
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        vector<int> id(N);
        for (int i = 0; i < N; i++) {
            id[nums2[i]] = i;
        }
        
        M = N;
        ST.resize(2*M);
        
        long res = 0;
        for (int i = 0; i < N; i++) {
           
            int num = id[nums1[i]];
            
            long smaller = getSum(0, num); 
            long bigger = N - 1 - num - (i - smaller); 
            res += smaller * bigger; 
            
            update(num);
        }
        return res;
    }
};
