//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll M= 1e9+7;
	ll solve(int ind, int last,vector<vector<ll>>& dp){
	    if(ind==0){
	        if(last==1)
	        return dp[0][last]= 1;
	       
	        return dp[0][last]= 2;
	       
	       //if(last==1) return 1;
	       //return 2;
	    }
	    if(dp[ind][last]!= -1) return dp[ind][last];
	    ll cur0=0, cur1=0;
	    cur0= solve(ind-1, 0, dp);
	    if(last!=1)
	    cur1= solve(ind-1, 1, dp);
	    return dp[ind][last]= (cur0%M+cur1%M)%M;
	   //return (cur0%M+cur1%M)%M;
	}
	ll countStrings(int n) {
	    // code here---
	   // if(n==1) return 2;
	   // int last= -1;
	   // vector<vector<ll>> dp(n, vector<ll>(3,-1));
	    
	   //// return dp[n-1][2]=solve(n-1, 2, dp);
	  
	   ////return solve(n-1, -1, dp);
	   vector<ll> dp(n+3, 0);
	   
	    dp[0]=0, dp[1]= 1;
	    for(int i=2; i<=n+2; i++){
	        dp[i]= (dp[i-1]+ dp[i-2])%M;
	    }
	    
	    return dp[n+2]%M;
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends