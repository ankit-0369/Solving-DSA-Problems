class Solution {
    private:
    int countGreater(vector<int>& nums, int x){
        int cnt=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=x){
                cnt++;
            }
        }
        // cout<<"cnt of "<<x<<" : "<<cnt<<endl;
        return cnt;
    }
public:
    int specialArray(vector<int>& nums) {
        int n= nums.size();
        int s=0, e= n;
        int m= s+(e-s)/2;
        while(s<=e){
           int cnt= countGreater(nums,m);
           if(m==cnt)
           return m;
           else if( cnt>m){
            s= m+1;
           }else
           e= m-1;
           m= s+ (e-s)/2;
        }
     return -1;
    }
};