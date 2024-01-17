//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int index, int cap_w, int wt[], int val[], vector<vector<int>>& memo){
        if(cap_w==0) return 0;
        if(index==0) return (wt[0]<= cap_w ? val[0] : 0);
        
        if(memo[index][cap_w]!= -1) return memo[index][cap_w];
        
        int noTake= 0 + solve(index-1, cap_w, wt, val, memo);
        int take=0;
        if(wt[index]<= cap_w) take= val[index]+
                    solve(index-1, cap_w- wt[index], wt, val, memo);
                    
        return memo[index][cap_w]= max(take, noTake);
    }
    int knapSack(int cap_w, int wt[], int val[], int n) 
    { 
       // Your code here---
       int index= n-1;
       vector<vector<int>> memo(n, vector<int>(cap_w+1, -1));
       return solve(index, cap_w, wt, val, memo);
       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends