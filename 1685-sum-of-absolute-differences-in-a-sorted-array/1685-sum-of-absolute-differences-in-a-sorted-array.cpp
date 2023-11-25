class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> pre(nums.size(),0);
        vector<int> suf(nums.size(),0);
        for(int i=1; i<nums.size(); i++){

            pre[i]= pre[i-1]+ nums[i-1];
        }
         for(int i=nums.size()-2; i>=0; i--){

            suf[i]= suf[i+1]+ nums[i+1];
        }
       
        for(int i=0; i<nums.size(); i++){

            nums[i]= nums[i]*i-pre[i] + suf[i] - nums[i]*(nums.size()-i-1);
        }
        return nums;
    }
    
};