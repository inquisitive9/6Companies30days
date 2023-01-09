class Solution {
public:
    int assign(vector<int>& roles,int mask) {
        int cnt = 0;
        for(int i = 0 ; i < roles.size() ;i++) {
            roles[i] = mask&1;
            cnt += roles[i];
            mask >>= 1;
        }
        return cnt;
    }

    bool isValid(vector<int>& roles,vector<vector<int>>& statements) {
        for(int i = 0 ; i < statements.size() ;i++) {
            if(roles[i] == 0) continue;
            for(int j = 0 ; j < statements.size() ;j++) {
                if(statements[i][j] == 2) continue;
                if(statements[i][j] != roles[j]) return false;
            }
        }
        return true;
    }

    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size() ;
        int mx = 0 ;
        vector<int> roles(n,0);
        int cnt = 1 << n;
        for(int mask = 1 ; mask < cnt ;mask++) {
            int cur = assign(roles,mask);
            if(isValid(roles,statements)) {
                mx = max(mx,cur);
            }
        }
        return mx;
    }


};
