class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int i=0;
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        int j=i;
        i++;
        while(i+1<nums.size()){
            if(nums[j]<= nums[j+1] && nums[i]> nums[i+1] || nums[j]>=nums[j+1] && nums[i]<nums[i+1]){
                return false;
            }
            
            i++;
        }
        return true;
        
    }
};