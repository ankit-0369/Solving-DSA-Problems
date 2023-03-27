class Solution {
public:
    int kItemsWithMaximumSum(int n1, int n0, int Neg1, int k) {
         if(k>n1+n0){
            return (2*n1 + n0-k);
        }else if(k>n1 && k<=n1+n0){
                return n1;
        }
         return k;
    }
};