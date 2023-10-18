//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> al[]) {
        // code here---
         vector<int> adjRev[V];
       int indegree[V] = {0};
       for(int i=0;i<V;i++){
           for(auto it:al[i])
           {
               adjRev[it].push_back(i);
               indegree[i]++;
           }
       }
       vector<int>ans;
       queue<int>q;
       
       for(int i=0;i<V;i++){
           if(indegree[i]==0)
           q.push(i);
       }
       
       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           ans.push_back(node);
           for(auto nbr:adjRev[node])
           {
               indegree[nbr]--;
               
               if(indegree[nbr]==0)
               q.push(nbr);
           }
       }
         sort(ans.begin(), ans.end());
         return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends