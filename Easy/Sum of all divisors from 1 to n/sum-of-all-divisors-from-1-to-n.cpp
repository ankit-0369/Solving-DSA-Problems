//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    // long long f(int n){
    //     long long sum= n;
    //     for(int i=1; i<=n/2; i++){
    //         if(n%i==0){
    //             sum+= i;
    //         }
    //     }
    //     return sum;
    // }
    long long sumOfDivisors(int n)
    {
        // Write Your Code here---
        long long sum=0;
        for(int i=1; i<=n; i++){
            // sum+= f(i);
            // cout<<i<<" "<<f(i)<<"\n";
            //As In total sum i will occur floor(n/i) times.
            sum+= i* floor(n/i);
            
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends