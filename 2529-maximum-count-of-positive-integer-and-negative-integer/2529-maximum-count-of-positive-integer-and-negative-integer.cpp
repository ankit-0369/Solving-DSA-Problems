class Solution {
public:
int countNegative(vector<int>& nums){
    int negIndex= -1;
     int s= 0, e= nums.size()-1;
        int m= s+ (e-s)/2;
        while(s<=e){
            if(nums[m]<0){
                negIndex= m;
                s= m+1;
            }else
            e= m-1;
            m= s+(e-s)/2;
        }
        return negIndex;
}

int countPositive(vector<int>& nums){
        int posIndex= -1;
        int s=0, e= nums.size()-1;
       int m= s+(e-s)/2;
        while(s<=e){
            if(nums[m]>0){
                posIndex= m;
                e= m-1;
            }else
            s= m+1;
            m= s+(e-s)/2;
        }

        return posIndex;
}

    int maximumCount(vector<int>& nums) {
        int posIndex=countPositive(nums);
        int negIndex=countNegative(nums);
      
        if(posIndex==-1 && negIndex==-1){
            return 0;
        }
        int pos=-1;
        if(posIndex>-1){
            pos= nums.size()-posIndex;
        }
        int neg=-1;
        if(negIndex>-1){
             neg= negIndex+1;
        }
       return max(neg,pos);
    }
};