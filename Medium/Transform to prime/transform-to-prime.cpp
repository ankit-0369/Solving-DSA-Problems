//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    private:
    bool isprime(int num){
        for(int i=2;i<num;i++){
            if(num%i==0)return false;
        }
        return true;
    }
    public:
    int minNumber(int arr[],int N)
    {
        
         
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum==1) return 1;
        
        if(isprime(sum)) return 0;
        
        int k=1;
        while(!isprime(sum+k)){
            k++;
        }
        return k;
       
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends