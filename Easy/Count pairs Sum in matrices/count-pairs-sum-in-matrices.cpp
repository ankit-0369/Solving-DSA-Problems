//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
    bool isPresent(vector<vector<int>>& mat, int tar){
        int n= mat.size();
        // int s=0, e= n*n-1;
        int s= 0, e= n-1;
        // cout<<tar<<" ";
        while(s<n && e>=0){
            
            // int m= s+ (e-s)/2;
            // int mr= m%n, mc= m/n;
            if(mat[s][e] == tar){
                // cout<<tar<<" ";
                return 1;
            }else if(mat[s][e] < tar){
                s++;
            }else e--;
        }
        
        return 0;
    }
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    // Your code goes here---
	    int cnt=0;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            
	           // bool q= isPresent(mat2, x-mat1[i][j]);
	            cnt+= isPresent(mat2, x-mat1[i][j]);
	           // if(q == 1){
	           //     cnt++;
	           //    // cout<<mat1[i][j]<<" "<<x-mat1[i][j]<<"\n";
	           // }
	        }
	    }
	    return cnt;
	    
	}
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends