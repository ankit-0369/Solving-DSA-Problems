// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s= 0, e= n;
        int firstBad=-1;
        int m;
        while(s<=e){
            m= s+ (e-s)/2;
            if(isBadVersion(m)){
                firstBad= m;
                e= m-1;
            }else
                s= m+1;

        }

        return firstBad;
    }
};