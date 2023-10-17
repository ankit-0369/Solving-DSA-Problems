//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int M= 1e9+ 7;
    
    int solve(int n, vector<int>& dp){
        if(n<=1) return n;
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]= (solve(n-1, dp) + solve(n-2, dp))%M;
    }
    int countWays(int n)
    {
        // your code here---
        //dp soln--
        vector<int> dp(n+2, -1);// since 0th step is not treated we need to considr 1-based indexing
        return solve(n+1, dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends