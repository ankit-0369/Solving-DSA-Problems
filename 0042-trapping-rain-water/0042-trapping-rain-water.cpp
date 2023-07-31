class Solution {
public:
    int trap(vector<int>& h) {
        //naive approach--- O(n) & O(n)
        int n= h.size();
        int mxl[n];
        int mxr[n];
        mxl[0]= h[0];
        mxr[n-1]= h[n-1];
        for(int i=1; i<n; i++){
            mxl[i]= max(h[i], mxl[i-1]);
        }

        for(int i= n-2; i>=0; i--){
            mxr[i]= max(mxr[i+1], h[i]);
        }

        //storing final value---
        int ans=0;
        for(int i=0; i<n; i++){
            ans+= min(mxl[i], mxr[i])-h[i];
        }

        return ans;
    }
};