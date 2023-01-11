class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> lett = {'A','C','G','T'};
        int size = bank.size();
        set<string> st;
        for(int i = 0 ; i < bank.size() ;i++) {
            st.insert(bank[i]);
        }
        queue<string> q;
        q.push(startGene);
        if(st.find(startGene) != st.end())
        st.erase(startGene);
        int lvl = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
            string word = q.front();
            q.pop();
            if(word == endGene) return lvl;
            for(int i = 0 ; i < word.size() ;i++) {
                char ch = word[i] ;
                for(int j = 0 ; j < lett.size() ;j++) {
                    word[i] = lett[j];
                    if(st.find(word) != st.end()) {
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
            }
            lvl++;
            
        }
        return -1;
    }
};
