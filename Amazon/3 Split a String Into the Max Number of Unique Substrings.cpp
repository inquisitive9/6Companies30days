class Solution {
public:
    int mx = 0;
    void func(string& s,set<string>& st,int idx,int len = 0) {
        if(idx >= s.size()) {
            int n = st.size();
            mx = max(mx,n);
            return ;
        }
        string temp = "";
        for(int i = idx ; i < s.size() ;i++) {
             temp += s[i];
            if(st.find(temp) != st.end()) continue;
            st.insert(temp);
            func(s,st,i+1,len+1);
            st.erase(st.find(temp));
        }
        
    }
    int maxUniqueSplit(string s) {
        set<string> st;
        func(s,st,0,0);
        return mx;
    }
};
