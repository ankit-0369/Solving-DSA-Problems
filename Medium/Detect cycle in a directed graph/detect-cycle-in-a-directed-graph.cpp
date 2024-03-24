//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here---
        int indeg[V]= {0};
        for(int i=0; i<V; i++){
            for(auto node: adj[i]) indeg[node]++;
        }
        
        queue<int> q;
        int cnt=0;
        for(int i=0; i<V; i++) if(indeg[i] == 0) q.push(i);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;
            for(auto neigh: adj[node]){
                indeg[neigh]--;
                if(indeg[neigh] == 0) q.push(neigh);
            }
        }
        
        return (cnt!= V);
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends