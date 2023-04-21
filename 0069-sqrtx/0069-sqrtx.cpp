class Solution {
public:
    int mySqrt(int n) {
        int start = 0;
        int end = n;
        long long int mid = start + (end - start)/2;
        int ans = -1;
        if(n==0 || n==1){
            return n;
        }
        while(start<=end){
            if(mid <= n/mid){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
};