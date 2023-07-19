//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.---
    //naive appproach---
    stack<int> k_ele;
    queue<int> left;
    int len= q.size();
    int i=0;
    while(i<k){
        k_ele.push(q.front());
        q.pop();
        i++;
    }

    while(!k_ele.empty()){
        
        q.push(k_ele.top());
        k_ele.pop();
    }
    
 
    i=0;
    while(i<(len-k)){
        q.push(q.front());
        q.pop();
        i++;
        
    }
    
    
    return q;
    

}