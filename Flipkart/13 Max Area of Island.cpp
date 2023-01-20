class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool isSafe(int x,int y,int m,int n,vector<vector<int>>& grid) {
        if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != 1)  {
            return false;
        }
        return true;
    }
    int mx = 0;
    void helper(vector<vector<int>>& grid,int x,int y,int& cnt) {
        cnt++;      
        grid[x][y] = 0;  
        for(int k = 0 ; k < 4 ;k++) {
            int newX = x+dx[k];
            int newY = y+dy[k];
            if(isSafe(newX,newY,grid.size(),grid[0].size(),grid)) {
                helper(grid,newX,newY,cnt);
            }
        }

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < m ;i++) {
            for(int j = 0 ; j < n ;j++) {
                if(grid[i][j] == 0) continue;
                int cnt = 0;
                helper(grid,i,j,cnt);
                mx = max(mx,cnt);
            }
        }
        return mx;
    }
};
