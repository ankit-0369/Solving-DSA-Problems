class Solution {
    // private:
    // int signFunc(long long p){
    //     if(p>0)
    //     return 1;
    //     if(p<0)
    //     return -1;
    //     else
    //     return 0;
    // }
public:
    int arraySign(vector<int>& nums) {
        int ctneg=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0)
            return 0;
          else if(nums[i]<0){
              ctneg++;
          }
        }
        if(ctneg & 1) return -1;// if odd neg no then -1
        
        return 1;
    }
};