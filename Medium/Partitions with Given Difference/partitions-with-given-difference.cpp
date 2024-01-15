//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int M= 1e9+7;
  int solve(int n, int sum, vector<int>& arr){
      
     
        vector<int> prev(sum+1,0), cur(sum+1,0);
        // prev[0]= cur[0]= 1; will not work as sum can also be  0
        if(arr[0]==0) prev[0]= 2;
        else prev[0]= 1;
        
        
        if(arr[0]!=0 && arr[0]<=sum) prev[arr[0]]= 1;
        
        for(int i=1 ; i<n; i++){
            
            for(int s=0; s<=sum; s++){
                
                int noTake= prev[s];
                int take= 0;
                if(arr[i]<=s) take= prev[s-arr[i]];
                cur[s]= (noTake+ take)%M;
            }
            
            prev= cur;
        }
        
        return prev[sum];
  } 
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here---
        int total=0;
        for(auto ele: arr) total+= ele;
        
        if(total-d<0 || (total-d)%2!=0) return 0;
        
        int sum= (total-d)/2;

        return solve(n, sum, arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends