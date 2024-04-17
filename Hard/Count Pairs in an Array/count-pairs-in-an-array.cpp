//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    
    int merge(int arr[], int temp[], int l, int m, int r){
        int i=l, j= m+1, k= l;
        int inv=0;
        while(i<=m && j<=r){
            if(arr[i] > arr[j]){
                
                inv+= (m-i+1);
                temp[k++]= arr[j++];
            }else{
                temp[k++]= arr[i++];
            }
        }
        
        while(i<=m) temp[k++]= arr[i++];
        while(j<=r) temp[k++]= arr[j++];
        
        for(int i=l; i<=r; i++) arr[i]= temp[i];
        
        return inv;
    }
    
    int solve(int arr[], int temp[], int l, int r){
        int inv= 0;
        if(l<r){
            int m= l + (r-l)/2;
            inv+= solve(arr, temp, l, m);
            inv+= solve(arr, temp, m+1, r);
            
            inv+= merge(arr, temp, l, m, r);
        }
        
        return inv;
    }
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here----
        for(int i=0; i<n; i++) arr[i]*= i;
        int temp[n]= {0};
        
        int ans= solve(arr, temp, 0, n-1);
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends