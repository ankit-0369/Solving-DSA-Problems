//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  
  int solve(int ind, int n, vector<int>& dp){
      if(ind<=0)
      return 0;
      if(ind==1) return 1;
      
      if(dp[ind]==-1){
          int dou= solve(ind/2, n, dp);
          int one= solve(ind-1, n , dp);
          dp[ind]= 1+ min(dou, one);
      }
      
      return dp[ind];
  }
  
    int minOperation(int n)
    {
        //code here.----
        // vector<int> dp(n+1, -1);
        // // dp[0]= 0;
        // // for(int i=1; i<n; i++){
            
        // // }
        // int ind= n;
        // return solve(ind,n, dp);
        
        
        int operations = 0;
        while(n) {
            if(n & 1)   n--;
            else    n /= 2;
            operations++;
        }
        return operations;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends