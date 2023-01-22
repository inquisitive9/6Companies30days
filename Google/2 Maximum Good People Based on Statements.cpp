class Solution {
public:
vector<int> func(int num, int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if(num & (1 << i))
        v.push_back(1);
        else
        v.push_back(0);
    }
    return v;
}

bool helper(vector<vector<int>> &statements, vector<int> &roles, int n)
{
           for(int i = 0 ; i < statements.size() ;i++) {
            if(roles[i] == 0) continue;
            for(int j = 0 ; j < statements.size() ;j++) {
                if(statements[i][j] == 2) continue;
                if(statements[i][j] != roles[j]) return false;
            }
        }
        return true;
}
int maximumGood(vector<vector<int>> &statements)
{
    int n = statements.size();
    vector<int> v(n);
    int num = 1<<n;
    int mx = 0;
    for(int i = 1 ; i < num ;i++) {
        vector<int> v = func(i,n);
        cout <<"\n";
        if(helper(statements,v,n)) {
            mx = max(mx,__builtin_popcount(i)) ;
        }
    }
    return mx;
}

};
