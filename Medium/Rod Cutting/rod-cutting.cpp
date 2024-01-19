//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here----
        vector<int> dp(n+1, 0);
        for(int req_len= 0; req_len<=n; req_len++) dp[req_len]= price[0]*req_len;
        
        for(int index=1; index<n; index++){
            
            for(int req_len=0; req_len<=n; req_len++){
                
                int notake= dp[req_len];
                int take= (index+1<=req_len) ? price[index] + dp[req_len-index-1] : -1e9;
                dp[req_len]= max(take, notake);
                
            }
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends