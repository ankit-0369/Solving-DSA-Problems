class Solution {
public:
    vector<int> getRow(int row) {
        vector<vector<int>> ans(row+1, vector<int>(1,1));
        for(int i=1; i<row+1; i++){
            
            for(int j=1; j<i; j++){
                int ele= ans[i-1][j-1]+ ans[i-1][j];
                ans[i].push_back(ele);
            }
            ans[i].push_back(1);
        }
        
        return ans[row];
    }
};