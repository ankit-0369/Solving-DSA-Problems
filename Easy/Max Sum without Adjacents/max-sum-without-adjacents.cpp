//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
// 	int solve(int *arr, int n, int ind){
// 	    if(ind<0) return 0; //means 1st index picked and then ind go out of bound
// 	    if(ind==0) return arr[ind]; //as 1st index not picked---
	    
// 	    int pick= arr[ind]+ solve(arr,n,ind-2);
// 	    int notPick= solve(arr,n, ind-1);  //again overlapping problem occurs so further optimization i nedd
	    
// 	    return max(pick, notPick);
// 	}

	int dpSolve(int *arr, int n, int ind, vector<int>& memo){
	    
	    if(ind<0) return 0;
	    if(ind==0) return memo[ind]= arr[ind];
	    
	    if(memo[ind]==-1){
	        int pick= arr[ind]+ dpSolve(arr,n,ind-2,memo);
	        int notPick= dpSolve(arr,n,ind-1, memo);
	        return memo[ind]= max(pick, notPick);
	    }
	    
	    return memo[ind];
	}

	int findMaxSum(int *arr, int n) {
	    // code here---
	   // int ind= n-1;
	   // return solve(arr,n, ind);
	   
	   //vector<int> memo(n, -1); //let memo[i] be the maxSum from 0 to ith ele.
	   //int ind=n-1;
	   //dpSolve(arr, n, ind, memo);
	   
	   //return memo[n-1];
	   
	}
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends