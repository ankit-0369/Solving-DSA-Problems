class Solution {
public:
    int arrangeCoins(int n) {
        if(n==1 ||n==2){
            return 1;
        }
        // if(n==3)
        //     return 2;
        int ans=2;
        int s=2, e=n/2;
        int m= s+(e-s)/2;
        while(s<=e){
                if((long long int)m*(m+1)/2<=n){
                    ans=m;
                    s= m+1;
                }else
                e= m-1;
                m= s+(e-s)/2;
        }
        
        return ans;
    }
};