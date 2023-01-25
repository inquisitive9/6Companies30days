class Solution {
public:
int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, (int)1e9));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int lvl = 0;
    pq.push({grid[0][0], {0, 0}});
    dist[0][0] = grid[0][0];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int dis = p.first;
        int x = p.second.first;
        int y = p.second.second;
        for (int k = 0; k < 4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (newX >= 0 && newY >= 0 && newX < n && newY < m)
            {
                int newdist = max(grid[newX][newY], dis);
                if (newdist < dist[newX][newY])
                {
                    dist[newX][newY] = newdist;
                    pq.push({newdist, {newX, newY}});
                }
            }
        }
    }
    return dist[n - 1][n - 1];
}

};
