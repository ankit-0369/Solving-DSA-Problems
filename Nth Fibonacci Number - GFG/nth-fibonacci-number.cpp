//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int m= 10e9+7;
    int fib(int n){
        if(n==1 || n==2){
            return 1;
        }
       
        return (fib(n-1)%m + fib(n-1)%m)%m;
    }
    int nthFibonacci(int n){
        // code here---
        int mod=1000000007;
        int  pprev=0;
        int prev=1;
        if(n==1) return 0;
        if(n==2) return prev;
        int curr=0;
        for(int i=1;i<n;i++){
         curr=(prev%mod+pprev%mod)%mod;
            pprev=prev%mod;
            prev=curr%mod;
        }
        return curr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends