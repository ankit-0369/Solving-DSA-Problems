class Solution {
public:
//     int solve(vector<int>& cost, int index){
        
//         if(index>=cost.size()){
//             return 0;
//         }
        
//         int step1= solve(cost, index+1);
//         int step2= solve(cost, index+2);
        
        
//     }
    int minCostClimbingStairs(vector<int>& cost) {
        //let dp[i] is the min cost to go from ith step to nth step---
        int n= cost.size();
            vector<int> dp(n+2, 0);
        dp[n]=0;
        for(int i=n-1; i>=0; i--){

            dp[i]= cost[i]+ min(dp[i+1] , dp[i+2]);
        }
        
        return min(dp[0], dp[1]);
    }
};