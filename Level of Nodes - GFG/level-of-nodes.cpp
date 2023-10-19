//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    // code here---
	      vector<int>vis(v,0);
        queue<int>q;
        q.push(0);
        q.push(-1);
        int ans=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp==x){
                return ans;
            }
            if(temp==-1){
                if(!q.empty()){
                    q.push(-1);
                    ans++;
                }
            }else{
                if(!vis[temp]){
                    vis[temp]=1;
            for(auto i:adj[temp]){
                q.push(i);
            }
           }
            }
        }
        return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends