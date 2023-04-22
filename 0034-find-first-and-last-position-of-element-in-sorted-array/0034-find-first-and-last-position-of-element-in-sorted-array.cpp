class Solution {
public:
   
   int Search(vector<int>& nums, int target){
        int s=0,  e= nums.size()-1;
        int m= s+ (e-s)/2;
       
        while(s<=e){
                if(nums[m]<target){
                  
                    s= m+1;
                }else if(nums[m]>target){
                    e= m-1;
                }else
                return m;
                m= s+(e-s)/2;
        }

        return -1;
   }
   
int lowerSearch(vector<int>& nums, int target){
 int s=0,  e= nums.size()-1;
        int m= s+ (e-s)/2;
       int res1=-1;
        while(s<=e){
               
                if(nums[m]<target){
                    res1= m;
                    s= m+1;
                }else{
                    e= m-1;
                }
                
                m= s+(e-s)/2;
        }

        return res1;
}

int upperSearch(vector<int>& nums, int target){
    int s=0,  e= nums.size()-1;
        int m= s+ (e-s)/2;
       int res1=-1;
        while(s<=e){
               
                if(nums[m]>target){
                    res1= m;
                    e= m-1;
                }else{
                    s= m+1;
                }
                
                m= s+(e-s)/2;
        }

        return res1;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
            int res1=-1,res2=-1;
           if(Search(nums,target)!=-1){
               res1=lowerSearch(nums,target);
               res2= upperSearch(nums,target);
                if(res1==-1){
                    res1=0;
                }else
                res1= res1+1;
                if(res2==-1){
                    res2=nums.size()-1;
                }else
                res2= res2-1;
                   v.push_back(res1);
      v.push_back(res2);
           }else{
                v.push_back(res1);
            v.push_back(res2);
           
           }
         
   

        return v;
    }
};