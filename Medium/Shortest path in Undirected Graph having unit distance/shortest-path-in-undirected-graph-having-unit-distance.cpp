//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
  void topoSort(int node, int vis[], vector<int> adj[], stack<int>& st){
      vis[node]= 1;
      for(auto neigh : adj[node]){
          if(!vis[neigh])
            topoSort(neigh, vis, adj, st);
      }
      
      st.push(node);
      return;
  }
  
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here------
        vector<int> adj[N];
        
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> dis(N, 1e8);
        
        dis[src]= 0;
        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int v= q.front();
            q.pop();
            
            for(auto neigh : adj[v]){
                if(dis[v] + 1 < dis[neigh]){
                    dis[neigh]= dis[v] + 1;
                     q.push(neigh);
                }
                
               
            }
        }
        
        for(int i=0; i<N; i++) if(dis[i] == 1e8) dis[i]= -1;
        
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends