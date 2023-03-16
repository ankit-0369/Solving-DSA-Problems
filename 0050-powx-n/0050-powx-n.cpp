class Solution {
private:

double solve(double x, long long int n){
    if(n==0)
    return 1;
    double small;
    if(n>0){
        if(n%2==0){
            x= x*x;
            return solve(x,n/2);

        }else{
                small= solve(x,n-1);
        }
        
    }
    return x*small;
}

public:
    double myPow(double x, int n) {

            double ans= 1.0;
            long long int nn= n;
            if(nn<0)
             nn*= -1;

            ans= solve(x,nn);
            if(n<0){
                ans= double(1.0)/double(ans);
            }
            return ans;







//iterative way ---O(logn)


 
    //    double ans= 1.0;
    //   long long int nn= n;
    //   if(nn<0){
    //       nn*= -1;
    //   }

    //    while(nn>0){
    //       if(nn%2==0){
    //           x= x*x;
    //           nn/=2;
    //       }else{
    //           ans= x*ans;
    //           nn= nn-1;
    //       }
    //    }
    //    if(n<0){
    //        return double(1.0)/double(ans);
    //    }

    //     return ans;
    }
};