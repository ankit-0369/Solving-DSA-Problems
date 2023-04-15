//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        // code here ----t.c:- O(nlogn) & O(1)
    int total=0;
    //  sort(arr.begin(),arr.end());
    //     for(int i=1; i<n; i++){
    //         if(arr[i]==arr[i-1]){
                
    //             total+= time[arr[i]-1];
                
    //         }else{
    //             total+= 1;
                
    //         }
    //     }

    //     return total;
    //t.c:- O(n) & auxilary-space:- O(n)
    int hash[n];
    for(int i=0; i<n; i++){
        hash[i]=0;
    }
    hash[arr[0]]=1;
    for(int i=1; i<n; i++){
        if(hash[arr[i]]==1){
            total+= time[arr[i]-1];
        }else{
            total+=1;
            hash[arr[i]]=1;
        }
    }
    return total;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        
        vector<int> time(n);
        Array::input(time,n);
        
        Solution obj;
        int res = obj.totalTime(n, arr, time);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends