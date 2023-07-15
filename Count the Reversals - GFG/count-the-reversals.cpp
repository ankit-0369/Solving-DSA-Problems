//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here--
    //first condn--
    if(s.size() & 1){//odd length of string
        return -1;
    }
    
    stack<char> st;
    int cnt=0;
    for(auto ch:s){
        if(ch=='{'){
            st.push(ch);
        }else{
            if(!st.empty() && st.top()!= '}'){
                st.pop();
            }else{
                st.push(ch);
            }
            
        }
    }
    
    while(!st.empty()){
        char ch1= st.top();
        st.pop();
        char ch2= st.top();
        st.pop();
        if(ch1==ch2){
            cnt++;
        }else
        cnt+= 2;
        
    }
    
    return cnt;
    
}