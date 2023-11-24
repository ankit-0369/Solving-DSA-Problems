class Solution {
public:
    int maxCoins(vector<int>& piles) {
     sort(piles.begin(), piles.end());
     int ans=0; 
    for(int s= piles.size()/3; s<piles.size(); s+=2){
        ans+= piles[s];
    }
     return ans;
    }
};