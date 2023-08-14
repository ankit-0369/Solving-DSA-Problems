//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.---
        //naive approach---
        // int hash[1000007]= {0};
        // for(auto num: nums){
        //     hash[num]++;
        // }
        // vector<int> ans;
        // for(int i=0; i<1000007; i++){
        //     if(hash[i]==1){
        //         ans.push_back(i);
        //     }
        // }
        
        // return ans;
        
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i=0;
        int n= nums.size();
        while(i+1<n){
            if(nums[i]==nums[i+1]){
                i+= 2;
            }else{
                ans.push_back(nums[i]);
                i++;
            }
        }
        
        if(nums[n-1]!= nums[n-2])
        ans.push_back(nums[i]);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends