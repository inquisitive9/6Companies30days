class Solution {
public:

   long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
 int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int cnt = 0;
        long long l = numsDivide[0];
        for(int i = 1  ; i < numsDivide.size() ;i++) {
            l = gcd(l,numsDivide[i]);
        }
        for(auto it:nums) {
            pq.push(it);
        }
        l = (int)l;
        if(pq.top() > l) {
            return -1;
        }
        while(!pq.empty()) {
            if(pq.top() > l) {
            return -1;
            }
            if(l % pq.top() == 0) {
                return cnt;
            }
            cnt++;
            pq.pop();
        }
        return -1;
    }

};
