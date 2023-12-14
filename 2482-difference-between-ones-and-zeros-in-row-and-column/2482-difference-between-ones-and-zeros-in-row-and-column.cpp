class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m= grid.size(), n= grid[0].size();
        
        vector<vector<int>> diff(m, vector<int>(n,-1));
        vector<int> row1(m,0), col1(n, 0);
        for(int i=0; i<m ; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                cnt+= grid[i][j];
            }
            row1[i]= cnt;
        }
         for(int i=0; i<n ; i++){
            int cnt=0;
            for(int j=0; j<m; j++){
                cnt+= grid[j][i];
            }
            col1[i]= cnt;
        }
        
        for(int i=0; i<m; i++){
            for(int j=0 ; j<n; j++){
                    
                diff[i][j]= 2*col1[j] + 2*row1[i]-m-n;
            }
        }
        
        return diff;
    }
};