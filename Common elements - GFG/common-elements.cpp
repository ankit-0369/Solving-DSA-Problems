//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            int i=0, j=0, k=0;
            vector<int> res;
            vector<int> com;
            while(i<n1 && j<n2){
                if(a[i]==b[j] ){
                    com.push_back(a[i]);
                    i++, j++;
                }else if(a[i]>b[j]){
                    j++;
                }else
                i++;
            }
            
            j=0;
            while(j<com.size() && k<n3){
                if(com[j]==c[k]){
                   res.push_back(com[j]);
                    j++, k++;
                }else if(com[j]<c[k]){
                    j++;
                }else
                k++;
            }
         
            //removing duplicates
              vector<int> final;
              if(res.size()==0){
                  final.push_back(-1);
                  return final;
              }
              for(i=0; i+1<res.size(); i++){
                  if(res[i]!=res[i+1])
                  final.push_back(res[i]);
              }
                
              final.push_back(res[i]);
            
            return final;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends