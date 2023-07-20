//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) {
    
    //sliding window concept---
    //process first window---
    queue<long long> q;
    vector<long long> ans;
    for(int i=0; i<k; i++){
        if(a[i]<0)
        q.push(i);
    }
    
    
    //loop to slide window---
    for(int i=k; i<n; i++){
        //check purana window---
        if(q.empty()){
            ans.push_back(0);
        }else{
            ans.push_back(a[q.front()]);
            
        }
        //removal of outside indexes from window---
        while(!q.empty() && i-q.front()>=k){
            q.pop();
        }
        //moving window to next by adding cur element---
        if(a[i]<0){
            q.push(i);
        }
        
    }
    
    //check last window---
    if(!q.empty()){
        ans.push_back(a[q.front()]);
    }else
    ans.push_back(0);
    
    return ans;
                                                 
 }