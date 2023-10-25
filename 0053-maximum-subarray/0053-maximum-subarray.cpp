class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum= nums[0];
        int curSum= max(0, nums[0]);
        for(int i=1; i<nums.size(); i++){
            curSum+= nums[i];
            maxSum= max(curSum, maxSum);
            curSum= max(0, curSum);
        }

        return maxSum;
    }
};