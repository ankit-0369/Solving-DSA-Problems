class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0, right=0;
        int res=0;
        int curSum=0;
        unordered_map<int,int> mp;
        while(right<nums.size()){
            int r= nums[right];
            mp[r]++;
            curSum+= r;
            while(mp[r]>1){
                int l=nums[left];
                curSum-=l;
                mp[l]--;
                left++;
            }
           //CurSum will hold sum from left to right pos of nums for cur subarray
            res= max(res,curSum);
            right++;
        }
        return res;
    }
};