class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int hash[100007]={0};
        for(int i=0; i<nums.size(); i++){
            if(!(nums[i]&1))
            hash[nums[i]]++;
        }
        int fre=0;
        int maxfre=INT_MIN;
        int res=-1;
        for(int i=0; i<100007; i++){
            if(!(i&1) && hash[i]!=0){
                if(hash[i]>maxfre){
                    maxfre= hash[i];
                    res=i;
                }else if(hash[i]==maxfre){
                    res= min(res,i);
                }
            }
        }

        return res;
    }
};