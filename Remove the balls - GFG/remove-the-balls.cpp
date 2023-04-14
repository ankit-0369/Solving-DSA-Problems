//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> col, vector<int> rad) {//t.c:- O(n) && auxilaty-space:- O(n)
        stack<pair<int,int>> st;
        st.push({col[0],rad[0]});
        int i=1, j=1;
        int n= col.size();
        while(i<n && j<n){
            if(!st.empty() && st.top().first==col[i] && st.top().second==rad[i]){
                st.pop();
                i++,j++;
            }else{
                st.push({col[i],rad[i]});
                i++,j++;
            }
        }
        
        return st.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends