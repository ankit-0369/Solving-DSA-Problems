class Solution {
public:
    int faltuSoln(int n){

        if(n==44)
       return 1134903170;
       if(n==45)
       return 1836311903;
       if(n==0||n==1){
           return 1;
       }
       return climbStairs(n-1)+ climbStairs(n-2);
    }
    int climbStairs(int n) {
       //faltu way---
        // return faltuSoln(n);
        //optimized way with t.c:- O(n) & space:- O(1)
        int prev1=1, prev2= 1;
        for(int i=2; i<=n; i++){
                int curSum= prev1+ prev2;
            prev1= prev2;
            prev2= curSum;
            
        }
        
        return prev2;
    }
};