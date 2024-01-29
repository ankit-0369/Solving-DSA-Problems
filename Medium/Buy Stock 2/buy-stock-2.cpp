//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int ind, bool buy, int n, vector<long long>&prices,
    vector<vector<long long>>& memo ){
        
        if(ind==n) return 0;
        
        int profit=0;
        if(memo[ind][buy]!= -1) return memo[ind][buy];
        if(buy){
            profit= max((-1*prices[ind] + solve(ind+1, 0,n,prices, memo)),
            solve(ind+1, 1, n, prices, memo) );
        }else{
            profit= max((prices[ind] + solve(ind+1, 1,n,prices, memo)),
            solve(ind+1, 0, n, prices, memo));
        }
        
        return memo[ind][buy]= profit;
    }
    long long maximumProfit(vector<long long>&prices, int n) {
    //     // Code here-----
    //     int index= 0;
    //   vector<vector<long long>> memo(n+1, vector<long long>(2, -1));
    //     return solve(index, 1, n, prices, memo);
    
    
        long long netProfit=0, bp= 1e8, sp= 0;
        for(int i=0; i+1<n; i++){

            if(prices[i+1]> prices[i]){
                //profit line h boss-
                bp= min(bp, prices[i]);
                sp= max(sp, prices[i+1]);
            }else{
                //loss line aane vla h sell it now---
                netProfit+= max((long long)0, (sp-bp));
                
                bp= 1e8;
                sp=0;
            }
        }
        netProfit+= max((long long)0, (sp-bp));
        return netProfit;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends