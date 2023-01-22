class Solution {
public:
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool isSafe(vector<vector<int>> &grid, int x, int y)
{

    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 1)
    {
        return false;
    }
    return true;
}
void helper(vector<vector<int>> &grid, int x, int y)
{
    grid[x][y] = 1;
    for (int k = 0; k < 4; k++)
    {
        int newX = x + dx[k];
        int newY = y + dy[k];
        if (isSafe(grid, newX, newY))
        {
            helper(grid, newX, newY);
        }
    }
}
int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 0)
            helper(grid, i, 0);

        if (grid[i][m - 1] == 0)
            helper(grid, i, m - 1);
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 0)
            helper(grid, 0, i);

        if (grid[n - 1][i] == 0)
            helper(grid, n - 1, i);
    }

    int cnt = 0;

    for(int i = 0 ; i < n ;i++) {
        for(int j = 0 ; j < m;j++) {
            if(grid[i][j] == 0) {
                cnt++;
                helper(grid,i,j);
            }
        }
    }

    return cnt;

}

};
