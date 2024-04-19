//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	bool isPresent(int a[], int x, int size){
	    int s= 0, e= size-1;
	   
	    while(s<=e){
	         int m= s + (e-s)/2;
	        if(a[m] == x) return true;
	        else if(a[m]<x) s= m+1;
	        else e= m-1;
	    }
	    
	    return false;
	}
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	    sort(b, b+m);
	    vector<int> ans;
	    for(int i=0; i<n; i++){
	        if(isPresent(b, a[i], m) == false) ans.push_back(a[i]); 
	    }
	    
	    return ans;
	} 
};
	

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<int> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends