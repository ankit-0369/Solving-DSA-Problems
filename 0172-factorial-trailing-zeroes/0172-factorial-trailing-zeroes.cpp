class Solution {
public:
    int trailingZeroes(int n) { //t.c- O(log5n) & auxilary-space:- O(1)
        int cntZero=0;
        while(n!=0){
            cntZero+= (n/5);
            n/= 5;
        }
        return cntZero;
    }
};