class Solution {
public:
    bool isPerfectSquare(int num) {//t.c:- O(logn) & auxilary-space:- O(1)
        if(num==1)
            return true;
        int s=1, e= num/2;
        int m= s+ (e-s)/2;

        while(s<=e){
            if((long long)m* (long long)m==num)
            return true;
            else if((long long)m* (long long)m> num){
                e=m-1;
            }else
            s= m+1;
            m= s+ (e-s)/2;
        }
        return false;
    }
};