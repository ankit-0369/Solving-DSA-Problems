//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool dfsCall(int node, int path[], int vis[], int check[], vector<int> adj[]){
      
      path[node]= 1;
      vis[node]=1;
      check[node]= 0;
      for(auto neigh: adj[node]){
          
          if(!vis[neigh]){
             bool call=  dfsCall(neigh, path, vis, check, adj);
          
              if(call) return true;
          }else if(path[neigh] == 1) return true;
      }
      
      path[node]= 0;
      check[node]= 1;
      return false;
  }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here----
        int vis[V]= {0};
        int path[V]= {0};
        int check[V]= {0};
        
        for(int i=0; i<V; i++){
            
            if(!vis[i])
                dfsCall(i, path, vis, check, adj);
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(check[i]) ans.push_back(i);
        }
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