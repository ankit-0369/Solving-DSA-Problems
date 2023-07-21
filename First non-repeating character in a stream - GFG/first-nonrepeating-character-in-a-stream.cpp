//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    queue<char> q;
		    int fre[26]= {0};
		    string ans;
		    q.push(s[0]);
		    for(int i=0; i<s.size(); i++){
		        fre[s[i]-'a']++;  //to check repetiviveness---
		        q.push(s[i]);
		        
		        while(!q.empty()){
		            if(fre[q.front()-'a']>1){
		                q.pop();
		            }else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        //agr q emty ho jaaye to simple # store kr lo---
		        if(q.empty())
		        ans.push_back('#');
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends