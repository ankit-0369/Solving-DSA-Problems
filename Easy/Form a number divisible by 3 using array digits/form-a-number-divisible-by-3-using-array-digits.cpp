//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int getDigitSum(int n){
      int sum=0;
      while(n!=0){
            sum+= (n%10);
            n/=10;
      }
      
      return sum;
  }
    int isPossible(int N, int arr[]) {
        // code here---
        int sum=0;
        for(int i=0; i<N; i++){
            sum+= getDigitSum(arr[i]);
        }
        
        if(sum%3==0)
        return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends