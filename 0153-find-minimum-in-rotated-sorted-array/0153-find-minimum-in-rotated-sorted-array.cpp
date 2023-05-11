class Solution {
public:
    int findMin(vector<int>& nums) {
       
        int n= nums.size();
        int s=0, e= n-1;
        int m= s+(e-s)/2;
        while(s<e){
            if(nums[m]>nums[0]){
                s= m+1;
            }else
            e= m;
            m= s+(e-s)/2;
        }
        int index= (s+1)%n;
        
        return min(nums[s],nums[index]);
    }
};