class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0, j= nums.size()-1;
        while(i<=j){ //O(n)-T.C  & O(1)-Auxilary-space
            if(nums[i]+nums[j]==target){
                return {i+1,j+1};
            }else if(nums[i]+nums[j]>target){
                j--;
            }else
              i++;
        }

        return{};
    }
};