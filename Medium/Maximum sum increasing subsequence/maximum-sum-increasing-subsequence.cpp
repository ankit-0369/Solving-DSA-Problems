//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	
	int solve(int arr[], int n, int ind, int prevInd){
	    if(ind<0)
	    return 0;
	    if(ind==0){
	        if(arr[ind]<arr[prevInd]) return arr[ind];
	        return 0;
	    }
	    int take=0;
	     int notTake= 0;
	     
	     if(prevInd==-1){
	         prevInd= ind;
	        take= arr[ind]+ solve(arr,n,ind-1, prevInd);
	        prevInd=-1;
	        notTake= 0+ solve(arr, n, ind-1, prevInd);
	     }else{
	         if(arr[ind]<arr[prevInd]){
	        prevInd= ind;
	        take= arr[ind]+ solve(arr,n,ind-1, prevInd);
	         }
	         notTake= 0+ solve(arr, n, ind-1, prevInd);
	    }
	   
	  
	    
	    
	  
	    
	    return max(take, notTake);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here----
	   // int ind= n-1, prev= -1;
	   // int take= arr[ind]+ solve(arr,n,ind-1, n-1);
	   // int notTake= 0 + solve(arr,n, ind-1, prev);
	   // return max(take, notTake) ;
	   
	   //return solve(arr, n, ind, prev);
	   
	    vector<int>dp(n,0);
	    dp[0]=arr[0];
	    int ans=arr[0];
	    for(int i=1; i<n; i++){
	        for(int j=i-1; j>=0; j--){
	            if(arr[j]<arr[i]){
	                dp[i]=max(dp[i],dp[j]);
	            }
	        }
	         dp[i]+=arr[i];
	        ans=max(ans,dp[i]);
	    }
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends