class Solution {
public:
    int maxProfit(vector<int>& p) {
      int bestbp= INT_MAX;
      int maxp= 0;
      //we hav eto maximize profit which means minimize bp and maximize selling price and buying price diffrence.

        for(int i=0; i<p.size(); i++){
            bestbp= min(bestbp, p[i]);
            if(p[i]>bestbp){
                maxp= max(maxp, p[i]-bestbp);
            }
        }

       return maxp;
    }
};