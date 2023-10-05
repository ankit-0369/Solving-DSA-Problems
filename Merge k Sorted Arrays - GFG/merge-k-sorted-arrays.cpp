//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{   
    
    public:
    //Function to merge k sorted arrays.
    
    class info{
      public:
      int data;
      int row, col;
      info(int val, int r, int c){
          this->data= val;
          this->row= r;
          this->col= c;
          
      }
      
    };
    
    class compare{
      public:
      bool operator()(info* a, info* b){
          return a->data > b->data;
          
          
      }
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here--
        int n= arr.size();
        priority_queue<info*, vector<info*>, compare> heap;
        for(int i=0; i<k; i++){
            int j=0;
            info* temp= new info(arr[i][0], i, j);
            heap.push(temp);
        }
        
        vector<int> ans;
        while(!heap.empty()){
            info* ele= heap.top();
            heap.pop();
            ans.push_back(ele->data);
            int r= ele->row;
            int c= ele->col;
            if(c+1<n){
                info* t= new info(arr[r][c+1], r, c+1);
            
            heap.push(t);
            }
            
            
        }
        
        return ans;
    }
};










//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends