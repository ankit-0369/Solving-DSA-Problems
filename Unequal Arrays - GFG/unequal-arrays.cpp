//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int n, vector<int> &a, vector<int> &b) {
        // code here
        long long sum1=0, sum2=0;
        long long ans=0;
        vector<int> a1[2], b1[2];//0th index even - 1st index odd
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
       for(int i=0; i<n; i++){
           if(abs(a[i])%2==0){
               a1[0].push_back(a[i]);
           }else
           a1[1].push_back(a[i]);
         
           if(abs(b[i])%2==0){
               b1[0].push_back(b[i]);
           }else
           b1[1].push_back(b[i]);
             sum1+= a[i];
             sum2+= b[i];
       }
    
    //   for(int i=0; i<a1[0].size(); i++){
    //       cout<<a1[0][i]<<" "<<a1[1][i]<<"\n";
    //   }
       
      if(sum1!= sum2 || a1[0].size()!= b1[0].size()){
          return -1;
      }
      for(int i=0; i<2; i++){
          int x;
          for(int j=0; j< a1[i].size() ; j++){
              x= abs(a1[i][j]- b1[i][j]);
              ans+= x/2;
          }
      }
    
    return ans/2;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends