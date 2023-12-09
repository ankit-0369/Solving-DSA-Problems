class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();
        // int ans= solve(row-1, col-1, grid);
        // return ans;

        vector<int> prev(col, 0);
        for(int i=0; i<row; i++){
                vector<int> cur(col, 0);
            for(int j=0; j<col; j++){
                
                if(grid[i][j]==1) cur[j]=0;
                else if(i==0 && j==0 ) cur[j]=1;
                else{
                    int upCell=0, leftCell=0;
                    if(i>0) upCell= prev[j];
                    if(j>0) leftCell= cur[j-1];
                    cur[j]= upCell+leftCell;
                }
            }

            prev= cur;
        }

        return prev[col-1];
    }
};