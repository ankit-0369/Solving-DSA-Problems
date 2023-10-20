class Solution {
public:
    int rob(vector<int>& nums) {
        //tabulation  \U0001f927<robbing using algo>----
//         int n= nums.size();
//         vector<int> dp(n, -1);
//         dp[0]= nums[0];
        
//         for(int i=1; i<n; i++){

//             int pick= nums[i];
//             if(i-2>=0) pick+= dp[i-2];
//             int notPick= dp[i-1];
            
//             dp[i]= max(pick, notPick);
//         }
        
//         return dp[n-1];
        //space optimized----
        int n= nums.size();
        int prev2= 0, prev1= nums[0];
        for(int i=1; i<n; i++){

            int cur= nums[i];
            if(i>1) cur+= prev2;
            cur= max(cur, prev1);
            prev2= prev1;
            prev1= cur;
        }
        
        return prev1;
    }
};