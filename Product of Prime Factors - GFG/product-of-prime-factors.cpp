//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int primeProduct(int n){
        //code here--
        //pahle even hatao then sara odd check krlo kitne divisor prime hai--
        long long int ans= 1;
        if(n%2==0){
            ans*= 2;
        }
        
        while(n%2==0){
            n/=2;
        }
        
        //odd part--
        for(int i=3; i*i<=n; i+=2){
            if(n%i==0){
                ans*=i;
            }
            while(n%i==0){
                n/=i;
            }
        }
        
        //agr prime n hai to kisi se divide nhi hoga--
        if(n>2)
        ans*= n;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.primeProduct(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends