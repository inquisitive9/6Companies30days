class Solution {
public:

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> mat(n, vector<int>(n, 1e9));
    for(int i = 0 ; i < n ;i++)  mat[i][i] = 0;
    for (auto it : edges)
    {
        mat[it[0]][it[1]] = it[2];
        mat[it[1]][it[0]] = it[2];
    }
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][via] != 1e9 && mat[via][j] != 1e9)
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }

    int minCities = INT_MAX;
    int city = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] <= distanceThreshold)
                cnt++;
        }
        if (minCities >= cnt)
        {
            minCities = cnt;
            city = i;
        }
    }

    return city;
}

};
