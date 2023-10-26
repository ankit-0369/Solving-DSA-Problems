class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int maxSum= INT_MIN;
        int minSum= INT_MAX;
        int n= nums.size();
        int curSum=0;
        for(int i=0; i<n; i++){
            maxSum= max(maxSum, curSum+ nums[i]);
            curSum+= nums[i];
            if(curSum<0) curSum=0;
        }
            curSum=0;
            for(int i=0; i<n; i++){
                curSum+= nums[i];
            minSum= min(minSum, curSum);
            cout<<curSum<<" "<<minSum<<"\n";
            if(curSum>0) curSum=0;
        }
                // cout<<maxSum<<" "<<minSum;
            return max( abs(maxSum), abs(minSum));
    }
};