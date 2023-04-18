class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s=0, e= nums.size()-1;
        int m= s+ (e-s)/2;
        while(s<=e){
            if(nums[m]==target){
                return m;
            }else if(target<nums[m]){
                e= m-1;
            }else
              s= m+1;
              m= s+(e-s)/2;
        }
     return -1;
    }
};