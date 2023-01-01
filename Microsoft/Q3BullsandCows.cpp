class Solution {
public:
 
string getHint(string secret, string guess)
{
    int n = secret.size();
    int bulls = 0;
    string newG = "";
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++)
    {
        if (secret[i] == guess[i])
        {
            bulls++;
        }
        else
        {
            cnt[secret[i]-'0']++;
            newG += guess[i];
        }
    }
    int cow = 0;
    for (int i = 0; i < newG.size(); i++)
    {
        if (cnt[newG[i]-'0'] > 0)
        {
            cow++;
            cnt[newG[i]-'0']--;
        }
    }
    string ans = to_string(bulls) + "A" + to_string(cow) + "B";
    return ans;
}

};
