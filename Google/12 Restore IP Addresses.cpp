class Solution {
public:
   bool isValid(string a) {
      if((a[0] == '0' && a.size() > 1) || a.size() ==  0 || stoi(a) > 255  || a.size() > 3) return false;
      return true;
  }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size()      ;
        vector<string> res;
        if(n < 4 || n > 12) {
            return res;
        }

        for(int i = 1 ; (i <= 3 && i < n-2) ; i++) {
            for(int j = i+1 ; (j < i+4 && j < n-1) ; j++) {
                for(int k = j+1; (k < j+4 && k < n) ;k++) {
                    string a = s.substr(0,i);
                    string b = s.substr(i,j-i);
                    string c = s.substr(j,k-j);
                    string d = s.substr(k,n-k);
                    if(isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                        string temp = a + '.' + b + '.' + c + '.' + d;
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }

};
