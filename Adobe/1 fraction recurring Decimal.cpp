class Solution {
public:
    string fractionToDecimal(int num, int den) {
        long long numerator = (long long)num;
        long long denominator = (long long)den;
        long long q = abs(numerator/denominator);
        long long r = abs(numerator%denominator);
        long long flag = 0;
         if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            flag = 1;
        }
        if(denominator < 0) denominator= denominator * -1;
        if(r==0) {
            if(flag) return "-" + to_string(q);
            return to_string(q);
        }
        unordered_map<long long,long long> mp;
        string ans = "";
        if(flag) {
            ans = "-" +  to_string(q);
        }
        else {
            ans = to_string(q);
        }
        ans += ".";
        mp[r] = ans.size();
        while (r!= 0)
        {
            r*=10;
            q = r/denominator;
            r = r%denominator;
             ans += to_string(q);
            if(mp.count(r)) {
                ans.insert(mp[r],"(");
                ans += ")";
                return ans;
            }
            mp[r] = ans.size();
        }
        return ans;
    }


};
