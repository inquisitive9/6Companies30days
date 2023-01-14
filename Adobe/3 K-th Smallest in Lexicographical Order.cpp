class Solution {
public:
    int cntNodes(long long n,long long cur) {
        long long nxt = cur+1;
        long long cnt = 0;
        cur = (long long)cur;
        while(cur <= n) {
            cnt += min(n-cur+1,nxt-cur);
            cur *= 10;
            nxt *= 10;
        }
        return (int)cnt;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k>0) {
            int cnt = cntNodes(n,cur);
            if(k >= cnt) {
                cur = cur+1;
                k -= cnt;
            }
            else
          {  cur*=10;
            k--;}
             
        }
        return cur;
    }
};
