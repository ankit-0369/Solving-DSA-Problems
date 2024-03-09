//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code here---
	    string ans="";
	    int low[26]= {0};
	    int up[26]= {0};
	    for(auto ch: str){
	        if((ch>='a' && ch<='z')){
	            if(low[ch-'a'] == 0){
	                
	                 ans+= ch;
	                low[ch-'a']= 1;
	            }
	        }
	        else if((ch>='A' && ch<='Z') ){
	            
	             if(up[ch-'A'] == 0){
	                 ans+= ch;
	                up[ch-'A']= 1;
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends