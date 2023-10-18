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
        
        vector<int> memo(n+1, -1);
        return solve(n, memo);
    }
};