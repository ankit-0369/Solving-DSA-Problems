//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
    // Complete the function
    int car=0;
    int sum=0;
    string s;
    
    int i= n-1, j= m-1;
    while(i>=0 && j>=0){
        sum= a[i--]+ b[j--]+ car;
        int d= sum%10;
        s.push_back(d+'0');
        car= sum/10;
        
    }
    while(i>=0){
        sum= a[i--]+car;
        int d= sum%10;
    s.push_back(d+'0');
        car= sum/10;
    }
    while(j>=0){
        sum= b[j--]+ car;
        int d= sum%10;
       s.push_back(d+'0');
        car= sum/10;
    }
    if(car!=0){
        s.push_back(car+'0');
    }
    i= s.size()-1;
    while(i>=0){
        if(s[i]=='0')
        s.pop_back();
        else
        break;
    }
    reverse(s.begin(),s.end());
    i= s.size()-1;
   
    return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends