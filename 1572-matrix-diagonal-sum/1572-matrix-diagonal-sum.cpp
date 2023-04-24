class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {//t.c:- O(n) & auxilary-space:- O(1)
        int i=0, j=0;
        int ct=0;
        int n= mat.size();
        int k=0 , l= n-1;
        while(i<n){
            ct+= mat[i][j] + mat[k][l];
            // cout<<mat[i][j]<<" "<<mat[k][l]<<" "<<endl;
            i++, j++, k++, l--;
        }
        if(n & 1){//n is odd
                ct-= mat[n/2][n/2];
        }
        return ct;
    }
};