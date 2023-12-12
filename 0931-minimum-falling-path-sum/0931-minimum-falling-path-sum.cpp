class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<int> prev(n, 1e9);
        for(int i=0; i<n; i++) prev[i]= matrix[0][i];
        
        for(int i=1; i<n; i++){
            vector<int> cur(n,0);
            for(int j=0; j<n; j++){
                int l= 1e8, r= 1e8, s= 1e8;
                s= prev[j];
                if(j-1>=0) l= prev[j-1];
                if(j+1<n) r= prev[j+1];
                
                cur[j]= matrix[i][j]+ min(s, min(l,r));
            }
            
            prev= cur;
        }
        int ans= 1e9;
        for(auto num:prev)
            ans= min(ans, num);
        return ans;
    }
};