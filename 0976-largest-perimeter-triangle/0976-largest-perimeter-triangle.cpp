class Solution {
public:
    int largestPerimeter(vector<int>& nums) {//time-complexity:- O(n) & auxilary-space: O(1)
        sort(nums.begin(), nums.end());
        for(int i= nums.size()-1; i-2>=0; i--){
            if(nums[i]<nums[i-1]+ nums[i-2]){
                    return nums[i]+ nums[i-1]+ nums[i-2];
            }
        }
        return 0;
    }
};