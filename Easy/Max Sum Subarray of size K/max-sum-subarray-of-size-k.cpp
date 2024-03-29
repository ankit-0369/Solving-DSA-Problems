//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        // code here 
        long curSum=0, maxSum=0;;
        for(int i=0; i<k; i++){
            curSum+=(long) arr[i];
        }
        
        maxSum=curSum;
        
        for(int i=k; i<n; i++){
            curSum-= arr[i-k];
            curSum+=(long) arr[i];
            maxSum= max(curSum, maxSum);
        }
        
        return maxSum;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends