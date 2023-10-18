class Solution {
public:
    int solve(int ind, vector<int>& memo){

        if(ind==0 ){
            return 0;
        }
        
        if(ind==1|| ind==2){

            return 1;
        }
        
        if(memo[ind]==-1){
                
            return memo[ind]= solve(ind-1, memo)+ solve(ind-2, memo)+ solve(ind-3, memo);
        }
        
        return memo[ind];
    }
    int tribonacci(int n) {
        
        // vector<int> memo(n+1, -1);
        // return solve(n, memo);
        if(n==0)
            return 0;
            
        
        int prev3= 0, prev2=1, prev1= 1;
        for(int i=3; i<=n; i++){
            
            int curVal= prev1+ prev2+ prev3;
            prev3= prev2;
            prev2= prev1;
            prev1= curVal;
            
        }
        
        return prev1;
    }
};