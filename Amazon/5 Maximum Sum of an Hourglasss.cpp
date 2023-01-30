class Solution {
public:
 
int maxSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int mxsum = 0;
    int sum = 0;
    for (int i = 0; i < m - 2; i++)
    {

        for (int j = 0; j < n - 2; j++)
        {
            // HOUR
            sum = 0;
            for (int k = i; k < i + 3; k++)
            {

                for (int c = j; c < j + 3; c++)
                {
                    if (k == i + 1)
                    {
                        sum = sum + grid[k][j + 1];
                        break;
                    }
                    sum = sum + grid[k][c];
                }
            }

            mxsum = max(mxsum, sum);
        }
    }
    return mxsum;
}


};
