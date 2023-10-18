//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int solve(vector<int>& h, int ind){
        if(ind<=0)
        return 0;
        
        int step1Cost= solve(h, ind-1) + abs(h[ind]- h[ind-1]);
        int step2Cost= INT_MAX;
        if(ind>1)
            step2Cost= solve(h,ind-2) + abs(h[ind]- h[ind-2]);
        
        return min(step1Cost, step2Cost);
    }
    
    int dpSolve(vector<int>& h, int ind, vector<int>& dp){
        
        if(ind==0)
        return 0;
        
        
         int step1Cost=  dpSolve(h,ind-1, dp) + abs(h[ind]- h[ind-1]);
         
         int step2Cost= INT_MAX;
         if(ind>1){
            //  step2Cost= (dp[ind-2]==-1) ? (dpSolve(h,ind-2, dp) + abs(h[ind]- h[ind-2])):(dp[ind-2]);
            if(dp[ind-2]!=-1){
                step2Cost= dp[ind-2] + abs(h[ind]- h[ind-2]);
            }else{
                step2Cost= dpSolve(h,ind-2,dp)+ abs(h[ind]- h[ind-2]);
            }
         }
         
        return dp[ind]= min(step1Cost, step2Cost);
    }
    
    int minimumEnergy(vector<int>& h, int n) {
        // Code here----
        
        //recursive soln--
        // return solve(h, n-1); T.L.E
        
        vector<int> dp(n, -1);
        dp[0]= 0;
        return dpSolve(h,n-1, dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends