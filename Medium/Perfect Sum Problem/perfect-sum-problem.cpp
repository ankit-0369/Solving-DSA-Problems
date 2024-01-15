//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int M= 1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here---
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        sort(arr, arr+n);
        reverse(arr, arr+n);
        for(int i=0; i<n; i++ ) dp[i][0]= 1;
        if(arr[0]<=sum) dp[0][arr[0]]= 1;
        
        for(int i=1 ; i<n; i++){
            
            for(int s=0; s<=sum; s++){
                
                int noTake= dp[i-1][s];
                int take= 0;
                if(arr[i]<=s) take= dp[i-1][s-arr[i]];
                dp[i][s]= (noTake+ take)%M;
               
            }
            
             
        }
        
        return dp[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends