//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here---
        int chars[26]= {0};
        for(auto ch:s){
            if(isalpha(ch)){
                 int ind=0;
                 if(islower(ch)) ind= ch-'a';
                 else ind= ch-'A';
                
                 chars[ind]=1;
            }
        } https://media.geeksforgeeks.org/img-practice/prod/courses/5/Web/Content/Clock-4_1706701529.gif
       
        for(int i=0; i<26; i++) if(chars[i]==0) return false;
        return  true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends