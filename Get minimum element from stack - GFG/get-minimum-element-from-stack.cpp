//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle= INT_MAX;
    stack<int> s;
    vector<pair<int, int>> arr;
    
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(arr.size()<1)
           return -1;
           return arr.back().second;
           
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
            if(arr.size()<1){
                return -1;
            }
            
             int ans= arr.back().first;
            arr.pop_back();
            return ans;
           
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
          minEle= (arr.size()<1) ? INT_MAX :  arr.back().second;
          minEle= min(minEle, x);
           arr.push_back({x,minEle});
        //  s.push(x);
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends