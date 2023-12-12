//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int r, int c, int n, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(c<0 || c>=n) return -1*1e9;
        if(r==0) return dp[r][c]= mat[r][c];
        
        if(dp[r][c]!=-1) return dp[r][c];
        
        int s= solve(r-1, c, n, mat, dp);
        int left= solve(r-1, c-1, n, mat, dp);
        int right= solve(r-1, c+1, n, mat, dp);
        
        return dp[r][c]= mat[r][c]+ max(s, max(left,right));
        
    } 
    
    int maximumPath(int n, vector<vector<int>> mat)
    {
        // code here----
        // int maxSum= -1e9;
        // vector<vector<int>> memo(n, vector<int>(n,-1));
        // for(int i=0; i<n; i++){
        //     maxSum= max(maxSum, solve(n-1, i,n, mat, memo));
        //     memo[n-1][i]= maxSum;
        // }
        
        // return maxSum;
        
        vector<vector<int> > dp(n, vector<int>(n,0));
        for(int i=0; i<n; i++)
        dp[0][i]= mat[0][i];
        
        for(int i=1; i<n; i++){
            
            for(int j=0; j<n; j++){
                
                 int l= -1e8, r= -1e8, s= -1e8;
                 if(j-1>=0) l= dp[i-1][j-1];
                 if(j+1<n) r= dp[i-1][j+1];
                 s= dp[i-1][j];
                 dp[i][j]= max(s, max(l,r))+mat[i][j];
        
            }
        }
        int ans= -1e9;
        for(int j=0; j<n; j++){
            
            ans= max(ans, dp[n-1][j]);
          
        }

        return ans;
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends