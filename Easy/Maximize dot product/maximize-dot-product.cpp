//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int solve(int i, int j, int a[], int b[], vector<vector<int>>& memo){
	    if(i<0 || j <0 || j>i) return 0;
	    
	    if(memo[i][j]!= -1) return memo[i][j];
	    
	    int take= a[i]*b[j] + solve(i-1, j-1, a, b, memo);
	    int notake= 0 + solve(i-1, j, a,b, memo);
	    
	    return memo[i][j]= max(take, notake);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here--
		int i= n-1, j= m-1;
		vector<vector<int>> memo(n, vector<int>(m, -1));
		return solve(i,j,a,b, memo);
		
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends