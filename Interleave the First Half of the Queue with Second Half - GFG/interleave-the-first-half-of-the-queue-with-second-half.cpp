//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        //naive approach---
        queue<int> q1, q2;
        int len= q.size();
        int i=0;
        while(!q.empty()){
            if(i<len/2){
                q1.push(q.front());
            }else{
                q2.push(q.front());
                
            }
            
            q.pop();
            i++;
        }
        vector<int> ans;
        while(!q1.empty() && !q2.empty()){
            ans.push_back(q1.front());
            ans.push_back(q2.front());
            q1.pop();
            q2.pop();
        }
        if(!q2.empty())
        ans.push_back(q2.front());
        
        return ans;
     }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends