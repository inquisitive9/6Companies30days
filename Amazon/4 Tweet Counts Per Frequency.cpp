class TweetCounts {
public:
    map<string,vector<int>> mp;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        if(freq == "minute") {
            int n = (endTime-startTime)/60+1;
            vector<int> res(n,0);
            for(auto it:mp[tweetName]) {
                if(startTime <= it && endTime >= it) {
                    res[(it-startTime)/60]++;
                }
            }
            return res;
        }
        if(freq == "hour") {
            int n = (endTime-startTime)/3600+1;
            vector<int> res(n,0);
            for(auto it:mp[tweetName]) {
                if(startTime <= it && endTime >= it) {
                    res[(it-startTime)/3600]++;
                }
            }
            return res;
        }
        else {
            int n = (endTime-startTime)/86400+1;
            vector<int> res(n,0);
            for(auto it:mp[tweetName]) {
                if(startTime <= it && endTime >= it) {
                    res[(it-startTime)/86400]++;
                }
            }
            return res;

        }
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
