class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //negative marking approach---
        vector<int> res;
        for(int i=0; i<nums.size(); i++){

            int index= abs(nums[i]);
            if(nums[index-1]>0){
                nums[index-1]*= -1;
            }
        }
        for(int i=0; i<nums.size(); i++){

            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
        
    }
};