//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long int M= 1e9+7;
   
    long long int solve(int n, vector<long long int>& dp){
        if(n<=1)
        return n;
        if(dp[n]!= -1)
        return dp[n];
        
        return dp[n]= (solve(n-1, dp)%M + solve(n-2, dp)%M)%M;
        }
   
    long long int topDown(int n) {
        // code here---
        vector<long long int> dp(n+1, -1); 
      return solve(n, dp);
    }
    long long int bottomUp(int n) {
        // code here---
       long long int prev1=1, prev2= 0;
        for(int i=2; i<=n; i++){
           long long int curVal= (prev1%M+ prev2%M)%M;
            prev2= prev1;
            prev1= curVal;
        }
        
        return prev1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends