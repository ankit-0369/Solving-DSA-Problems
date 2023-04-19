//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string str, int x){
        // code here
        queue<int>q;
        for(int i=0;i<n;i++){
            if(str[i]=='1'){
                q.push(i);
            }
        }
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            int st=ind-x>=0?ind-x:0;
            int end=ind+x<=(n-1)?ind+x:n-1;
            for(int i=st;i<=end;i++){
                str[i]='1';
            }
            
        }
        int t=count(str.begin(),str.end(),'0');
        return t==0;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends