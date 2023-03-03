class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
       // vector<int> running_sum;
        int cur=0;
        for(int i=1; i<nums.size(); i++){
          //   cur+= nums[i];
          // running_sum.push_back(cur);
            nums[i]+= nums[i-1];
        }
        
        return nums;
    }
};