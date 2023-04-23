class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
       //brute force...
        // int i=0, op=0;
        // int zero= 0;
        // while(i<nums.size() && op<nums.size()){

        //     if(nums[i]==0){
        //             zero++;
        //         int j= i+1;
        //         for(; j<nums.size(); j++){

        //             nums[j-1]= nums[j];
        //         }
        //         nums[j-1]= nums[i];
                
        //     }else
        //          i++;
        //          op++;
        // }

        // for(int i= nums.size()-zero; i<nums.size(); i++){
        //     nums[i]= 0;
        // }

        //two pointer approach...

        int i=0, j=0;
        while(i<nums.size()){

            if(nums[i]!=0)
                swap(nums[i++], nums[j++]);
               else 
                   i++;
        }
    }
};