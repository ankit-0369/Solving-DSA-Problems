class Solution {
public:
    int maxProduct(vector<int>& nums) {
//         int curPro= 1;
//         int maxPro= INT_MIN;
//         for(int i=0; i<nums.size(); i++){

//             maxPro= max(maxPro, curPro*nums[i]);
//             curPro*= nums[i];
//             curPro= max(1, curPro);
//         }
//         return maxPro;
        
      int pref=1, suff= 1;
        int ans= INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(pref==0) pref=1;
            if(suff==0) suff= 1;
            pref*= nums[i];
            suff*= nums[nums.size()-i-1];
          ans= max(ans, max(pref, suff));
            
        }
        
        return ans;
    }
};