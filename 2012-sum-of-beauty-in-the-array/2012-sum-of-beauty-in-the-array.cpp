class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n =nums.size();
        int pre[n];//its ith value will be max of 0 to i-1 elements
        int suf[n];//its ith value will be min of all elements from i+1 to n-1.
        pre[0]= 0;
        suf[n-1]= INT_MAX;
        for(int i=1; i<n; i++){
            pre[i]= max(pre[i-1], nums[i-1]);
        }
        for(int i= n-2; i>=0; i--){
            suf[i]= min(suf[i+1], nums[i+1]);
            
        }
        int totalbeauty= 0;
        for(int i= 1; i<n-1; i++){
            if(nums[i]>pre[i] && nums[i]<suf[i]){
                totalbeauty+= 2;
            }else if( nums[i]>nums[i-1] && nums[i]<nums[i+1]){
                totalbeauty+= 1;
            }
            // else
            //  totalbeauty+= 0;
        }
        
        return totalbeauty;
    }
};