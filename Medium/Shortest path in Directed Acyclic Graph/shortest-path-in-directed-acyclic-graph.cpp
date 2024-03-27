//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void topoSort(int node, int vis[], stack<int>& st, vector<pair<int,int>> adj[]){
        
        vis[node]= 1;
        for(auto neigh : adj[node]){
            int v= neigh.first; //node val
            // int wt= neigh.second; // distance of neigh from node---
            if(!vis[v])
                topoSort(v, vis, st, adj);
        }
        
        st.push(node);
        return;
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here----
        //creating a graph--
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++)
        {
            int u= edges[i][0];
            int v= edges[i][1], wt= edges[i][2];
            
            adj[u].push_back({v, wt}); //  u____wt___>v
        }
        
        //using dfs way for topo sort--
        stack<int> st;
        int vis[N]= {0};
        for(int i=0; i<N; i++){
            if(!vis[i])
                topoSort(i, vis, st, adj);
        }
        
        vector<int> dis(N, 1e8);
        dis[0]= 0; //src node is 0.
        while(!st.empty()){
            int node= st.top();
            st.pop();
            
            for(auto neigh: adj[node]){
                int v= neigh.first;
                int wt= neigh.second;
                if(wt + dis[node] < dis[v]){
                    dis[v]= wt+ dis[node];
                }
            }
            
        }
        
        for(int i=0; i<N; i++){
            if(dis[i] == 1e8) dis[i]= -1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends