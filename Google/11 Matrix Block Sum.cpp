class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
            int n = mat.size() ;
            int m = mat[0].size();
            vector<vector<int>> res(n,vector<int>(m,0));
            for(int i = 0 ; i < n ;i++) {
                for(int j = 0 ; j < m ;j++) {
                    
                    for(int r = max(0,i-k) ; r <= min(i+k,n-1) ;r++) {
                        for(int c = max(0,j-k) ; c <= min(j+k,m-1) ;c++) {
                            res[i][j] += mat[r][c];
                        }
                    }
                }
            }
            return res;
    }
};
