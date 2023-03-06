class Solution {
public:
    int findDuplicate(vector<int>& nums) {
            
        //negative marking approach---
        int i=0;
        int res=-1;
        while(i<nums.size()){
        
            nums[abs(nums[i])]*= -1;
            if(nums[abs(nums[i])]>0){

                return abs(nums[i]);
               
            }
            i++;
        }
      
          return res;
    }
};