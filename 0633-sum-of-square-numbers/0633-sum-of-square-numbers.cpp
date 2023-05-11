class Solution {
    private:
    bool searchNo(int x, int tar){
                int e= tar-1;
            int s=0;
            int m= s+(e-s)/2;
            while(s<=e){
                long long sum= (long long)m * (long long)m + (long long)x * (long long)x;

                if(sum==tar){
                    return true;
                }else if(sum>tar){
                    e= m-1;
                }else
                s=m+1;
                m= s+(e-s)/2;
            }
            return false;
    }
public:
    bool judgeSquareSum(int c) {
        if(c==0 || c==1)
        return true;
        for(int i=0; (long long)i* (long long)i<c; i++){
            bool check= searchNo(i,c);
            if(check)
            return true;
        }
        return false;
    }
};