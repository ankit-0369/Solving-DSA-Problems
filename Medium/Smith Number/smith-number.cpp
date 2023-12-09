//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  int digitSum(int n){
      int sum=0;
      while(n!=0){
          sum+= n%10;
          n/=10;
      }
      return sum;
  }
  
  bool isPrime(int n){
      if(n==1) return false;
      for(int i=2; i<= sqrt(n); i++){
          if(n%i==0) return false;
      }
      return true;
  }
  
    int sumOfPrimeFactor(int num){
        
        int sum = 0;
        
        for(int i = 2; i<=num; i++){
            
            //first factor always prime hoga tho jab tak divide hoga divide krege aur sum find krege
            while(num%i == 0){
                sum += digitSum(i);
                num /= i;
            }
        }
        
        return sum;
    }
    
  
    int smithNum(int n) {
        // code here----
        if(isPrime(n)) return 0;
        
        int sum= digitSum(n);
       
        
        return sum== sumOfPrimeFactor(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends