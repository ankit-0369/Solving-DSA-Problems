class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //time-complexity:- O(n) & auxilary- O(n) taking for result vector---
        int maxi= *max_element(candies.begin(), candies.end());
        vector<bool> result;
        for(int i=0; i<candies.size(); i++){
            if(candies[i]+extraCandies>=maxi){
                result.push_back(1);
            }else
            result.push_back(0);
        }
        return result;
    }
};