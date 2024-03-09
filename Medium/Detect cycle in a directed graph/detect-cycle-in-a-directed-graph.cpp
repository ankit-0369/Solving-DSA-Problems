//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.---
    bool dfs(int sr, int vis[], int path[], vector<int> adj[]){
        vis[sr]= 1;
        path[sr]= 1;
        for(auto neigh: adj[sr]){
           
           if(!vis[neigh]){
               bool call= dfs(neigh, vis, path, adj);
               if(call) return true;
               
           }
           
           if(vis[neigh] && path[neigh]) return true;
           
        }
        
        path[sr]= 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here---
        int vis[V]= {0};
        int path[V]= {0};
        for(int node= 0; node<V; node++){
            
            if(!vis[node]){
                bool check= dfs(node, vis, path, adj);
                if(check) return true;
            }
        }
        
        return false;
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