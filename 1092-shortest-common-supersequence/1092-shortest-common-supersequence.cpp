class Solution {
public:
    string getLCS(string s1, string s2){
        int m= s1.size(), n= s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++){
            
            for(int j=1; j<=n; j++){
                if(s1[i-1]== s2[j-1]){
                    dp[i][j]= 1+ dp[i-1][j-1];
                }else
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        string ans= "";
        int len=m+n-dp[m][n];
      
        
      int i=m, j= n;
        while(i>0 && j>0){
            
            if(s1[i-1]==s2[j-1]){
                ans+= s1[i-1];
                i--, j--;
                
            }else{
                if(dp[i-1][j] > dp[i][j-1]){
                   
                    ans+= s1[i-1];
                     i--;
                }
                else{
                    ans+= s2[j-1];
                    j--;
                }
            }
        }
        
        while(i>0) ans+= s1[i-- -1];
        while(j>0) ans+= s2[j-- -1];
        
        
        return ans;
        
    }
    
  
    string shortestCommonSupersequence(string str1, string str2) {
        string ans= getLCS(str1, str2);
        reverse(ans.begin(), ans.end());
       return ans;
        
    }
};