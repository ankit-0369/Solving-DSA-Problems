class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
//         int n= triangle.size();

//         vector<vector<int>> dp(n, vector<int>(n,0));
//         for(int i=0; i<n; i++)
//         dp[n-1][i]= triangle[n-1][i];

//         for(int i= n-2; i>=0; i--){

//             for(int j=i; j>=0; j--){
//                 int dn= triangle[i][j]+ dp[i+1][j];
//                 int dg= triangle[i][j]+ dp[i+1][j+1];
//                 dp[i][j]= min(dn, dg);
//             }
//         }

//         return dp[0][0];
        int n= triangle.size();
        vector<int> post(n,0);
        for(int i=n-1; i>=0; i--){
            vector<int> cur(n,0);
            for(int j= i; j>=0; j--){
                if(i==n-1){
                    cur[j]= triangle[i][j];
                }else{
                    
                int dn= triangle[i][j]+ post[j];
                int dg= triangle[i][j]+ post[j+1];
                cur[j]= min(dn,dg);
                }
                
            }
            post= cur;
        }
        return post[0];
    }
    
};