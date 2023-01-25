class Solution
{
public:
    int helper(int stIdx, int m, int n, vector<bool> &taken, vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int mx = 0;
        for (int i = 0; i < m; i++)
        {
            if (taken[i] == true)
                continue;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (students[stIdx][j] == mentors[i][j])
                {
                    cnt++;
                }
            }
            taken[i] = true;
            cnt = cnt + helper(stIdx + 1, m, n, taken, students, mentors);
            taken[i] = false;
            mx = max(mx, cnt);
        }
        return mx;
    }
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int m = mentors.size();
        int n = students[0].size();
        vector<bool> taken(m, false);
        return helper(0, m, n, taken, students, mentors);
    }
};
