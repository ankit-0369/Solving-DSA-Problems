class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m= mat.size();
        int n= mat[0].size();
        if(m*n!= r*c)
        return mat;
        vector<vector<int>> res;
        int p=0, q=0;
        for(int i=0; i<r; i++){
            vector<int> temp;
            for(int j=0; j<c; j++){
                temp.push_back(mat[p][q]);
                if(q==n-1){
                    p++;
                    q=0;
                }else{
                    q++;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};