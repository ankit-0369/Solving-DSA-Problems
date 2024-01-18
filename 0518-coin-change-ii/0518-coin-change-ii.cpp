class Solution {
public:
// int solve(int index, int tar, vector<int>& coins, vector<vector<int>>& memo){
//     if(index==0){
//         return (tar%coins[0] == 0);
//     }
//     if(memo[index][tar]!= -1) return memo[index][tar];
//     int noTake= solve(index-1, tar, coins, memo);
//     int take=0;
//     if(tar>=coins[index]) take= solve(index, tar-coins[index], coins, memo);

//     return memo[index][tar] = (take+ noTake);
// }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        // vector<vector<int>> memo(n, vector<int>(amount+1, -1));
        // return solve(n-1, amount, coins, memo);
        vector<int> prev(amount+1, 0), cur(amount+1, 0);
        for(int t= 0; t<=amount; t++) prev[t]= (t%coins[0]==0);

        for(int index=1; index<n; index++){

            for(int tar= 0; tar<=amount; tar++){
                    int noTake=prev[tar];
                    int take= (tar>=coins[index]) ? cur[tar-coins[index]] : 0;
                    cur[tar]= (noTake+take);
            }
            prev= cur;
        }

        return prev[amount];
    }
};