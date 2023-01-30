class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it:arr) pq.push(it);
        long long mas = mass;
        while(!pq.empty()) {
            int ele = pq.top();
            pq.pop();
            if(ele <= mas) {
                mas+=ele;
            }
            else
            return false;
        }
        return true;
    }
};
