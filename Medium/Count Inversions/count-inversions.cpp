//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    
    long long int merge(long long arr[], long long temp[], int l, int m, int r){
        
        int i= l, j= m+1, k= l;
        long long int inv= 0;
        while(i<=m && j<=r){
            if(arr[i] > arr[j]){
                temp[k++]= arr[j];
                inv+= (m-i + 1);
                
                j++;
            }else{
                temp[k++]= arr[i];
                i++;
            }
        }
        
        while(i<=m) temp[k++]= arr[i++];
        while(j<=r) temp[k++]= arr[j++];
        
        //copy the temp in the original arr====
        
        for(int i=l; i<=r; i++){
            arr[i]= temp[i];
        }
        
        return inv;
    }
    
    long long int solve(long long arr[], long long temp[], int l, int r){
        long long int invCnt= 0;
        
        if(l<r){
            int m= l + (r-l)/2;
            invCnt+= solve(arr, temp, l, m);
            invCnt+= solve(arr, temp, m+1, r);
            
            invCnt+= merge(arr, temp, l, m, r);
        }
        
        return invCnt;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here----
        long long temp[n]= {0};
        int l= 0, r= n-1;
        return solve(arr, temp, l, r);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends