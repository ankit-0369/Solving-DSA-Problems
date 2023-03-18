
#define m 1000000007
class Solution {
private:
long long mypow(long long x, long long y){
            if(y==0){
                return 1;
            }
    //  long long ans= mypow(x,y/2);
    //  ans*= ans;
    //  ans%=m;
    //  if(y%2==1){
    //      ans*=x;
    //      ans%= m;
    //  }    
    long long ans;
    if(y%2==0){
        ans= mypow(x,y/2);
        ans*= ans;
        ans%= m;
    }else{
        ans= mypow(x,y-1);
        ans*= x;
        ans%=m;
    }

     return ans;   
}
public:
    int countGoodNumbers(long long n) {
     
       int ans= 0;
      long long j= floor(n/2);
      long long i= n-j;
      
     
    //    cout<<" first: "<<mypow(5,i)<<" second : "<<mypow(4,j);
      
      
       ans= (mypow(5,i) * mypow(4,j))%m;
        
        return ans;
    }

};