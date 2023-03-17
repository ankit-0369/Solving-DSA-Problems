class Solution {

void reverse(vector<int>& nums, int index){
    int i= index, j= nums.size()-1;
    while(i<=j){
        swap(nums[i++], nums[j--]);
    }

    return;
}

public:
    void nextPermutation(vector<int>& nums) { // O(n) && O(1)
        int n= nums.size();
        int index= -1;
       //find first pivot no from right--
        for(int i=n-1; i-1>=0; i--){
                    if(nums[i]>nums[i-1]){
                        index= i-1; //first min no from right.
                        break;
                    }
        }
        //if pivot not exist then reverse complete nums---
          if(index<0)
          {
              reverse(nums,0);
              return;
          } 
        //find first greater value than nums[index] and then swap it with it
        int nextindex= 0;
        int min= INT_MAX;
        for(int i= index+1; i<n; i++){
                    if(nums[i]>nums[index] && nums[i]<=min){
                        min= nums[i];
                        nextindex= i;
                    }
        }
        swap(nums[index], nums[nextindex]);
        // cout<<" index: "<<index<<" min: "<<min<<" "<<nextindex;
        // reverse all value right to the index--
        reverse(nums, index+1);

    return;
 }
};