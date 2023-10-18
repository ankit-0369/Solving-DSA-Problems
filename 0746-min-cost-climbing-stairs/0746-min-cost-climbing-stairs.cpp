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
//         int n= cost.size();
//             vector<int> dp(n+2, 0);
//         dp[n]=0;
//         for(int i=n-1; i>=0; i--){

//             dp[i]= cost[i]+ min(dp[i+1] , dp[i+2]);
//         }
        
//         return min(dp[0], dp[1]);
        
//             int n= cost.size();
//             vector<int> dp(n+1, -1); //0th to ith step
//         dp[0]= 0;
//         for(int i=1; i<=n; i++){
//             int fs= dp[i-1] + cost[i-1];
//             int ss= INT_MAX;
//             if(i>1)
//                 ss= dp[i-2]+ cost[i-1];
            
//             dp[i]= min(fs, ss);
//         }
        
//         return dp[n];
        int n= cost.size();
        int next1=0, next2=0;
        for(int i= n-1; i>=0; i--){
           int fs= cost[i]+ next1;
            int ss= cost[i]+ next2;
            int cur= min(fs, ss);
            next2= next1;
            next1= cur;
        }
        
        return min(next1, next2);
    }
};