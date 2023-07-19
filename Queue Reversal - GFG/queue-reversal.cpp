//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{   private:
    queue<int> method1(queue<int> q){
         stack<int> s;
      while(!q.empty()){
          s.push(q.front());
          q.pop();
      }
      
      while(!s.empty()){
          q.push(s.top());
          s.pop();
      }
      return q;
    }
    
    queue<int> method2(queue<int> q){
        //base case---
        if(q.size()==1){
            return q;
        }
        int val= q.front();
        q.pop();
        queue<int> small= method2(q);
        small.push(val);
        return small;
    }
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here
        return method1(q);
        
        return method2(q);
    }
    
    
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends