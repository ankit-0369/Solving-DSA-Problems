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
      
        
        // sort(nums.begin(), nums.end()); //O(nlogn)
        // for(int i=0; i+1<n; i++){
        //     if(nums[i]==nums[i+1]){
        //         ans= nums[i];
        //         break;
        //     }
        // }
        //brute force approch
        //         int res=0;
        //         bool found= false;
        // for(int i=0; i<n-1; i++){
            
        //     for(int j=i+1; j<n; j++){
        //             if(nums[i]==nums[j]){
        //                 res= nums[i];
        //                 found= true;
        //                 break;
        //             }
        //     }
        //     if(found){
        //         break;
        //     }
        // }

        return res;
    }
};