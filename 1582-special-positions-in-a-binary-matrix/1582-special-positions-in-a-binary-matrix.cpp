class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rowLen= mat.size();
        int colLen= mat[0].size();
        vector<int> row(rowLen, 0), col(colLen,0);
        for(int i=0; i<rowLen; i++){
            int cnt=0;
            for(int j=0; j<colLen; j++){
                cnt+= mat[i][j];
            }
            row[i]= cnt;
        }
        for(int j=0; j<colLen; j++){
            int cnt=0;
            for(int i=0; i<rowLen; i++){
                cnt+= mat[i][j];
            }
            col[j]= cnt;
        }
        int ans=0;
        for(int i=0; i<rowLen; i++){
            for(int j=0; j<colLen; j++){
                ans+= (mat[i][j]==1 && row[i]==1 && col[j]==1);
            }
        }
        
        return ans;
    }
};