//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function---
       long sumXOR = 0;
        for (int i = 0; i < 31; i++) {
            int countZero = 0;
            int countOne = 0;

            for (int j = 0; j < n; j++) {
                if ((arr[j] & (1 << i)) == 0) {
                    countZero++;
                } else {
                    countOne++;
                }
            }

            // For each bit position, add the contribution of XOR for 0s and 1s.
            sumXOR += (long) countZero * countOne * (1 << i);
        }

        return sumXOR;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends