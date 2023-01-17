class Solution {
public:
int allbuy(vector<int> &price, vector<int> &needs)
{
    int sum = 0;
    for (int i = 0; i < needs.size(); i++)
    {
        sum += (price[i] * needs[i]);
    }
    return sum;
}

int minPrice = 0;
bool isPossible(vector<int>& needs,vector<int>& special) {
    int n = needs.size();
    for(int i = 0  ; i < n ;i++) {
        if(special[i] > needs[i]) {
            return false;
        }
    }
    return true;
}
void helper(vector<int> &price, vector<vector<int>> &special, vector<int> &needs,int idx,int curPrice) {
    if(curPrice >= minPrice) return ;
    if(idx == special.size()) {
         curPrice += allbuy(price,needs);
        if( curPrice < minPrice) {
            minPrice =  curPrice;
        }
        return ;
    }
    vector<int> offer = special[idx];
    int n = needs.size();
    if(isPossible(needs,offer)) {
        vector<int> updateneed;
        for(int i = 0 ; i < n ; i++) {
            updateneed.push_back(needs[i]-offer[i]);
        }
        helper(price,special,updateneed,idx,curPrice+offer[n]);
    }
    else {
        helper(price,special,needs,idx+1,curPrice);
    }
}

int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
{
        minPrice = allbuy(price, needs);
        helper(price,special,needs,0,0);
        return minPrice;
}

};
