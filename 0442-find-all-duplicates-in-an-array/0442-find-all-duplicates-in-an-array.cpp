class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       
//        int hash[100007]={0};
//        for(int i=0; i<a.size(); i++){
//            hash[a[i]]++;
//        }

//        vector<int> v;
//        for(int i=1; i<=a.size(); i++){
//            if(hash[i]==2){
//                v.push_back(i);
//            }
//        }
//        return v;

//     // sort(a.begin(), a.end());
//     // for(int i=0; i<n-1; i++){
//     //     if(a[i]==a[i+1]){
//     //         a.erase(a.begin()+i);
//     //     }
//     // }

//     // return a;
        //negative approach---
        // int n= nums.size();
         vector<int> res;
         // int k=0;
        
        for(int i=0; i<nums.size(); i++){
            
            int index= abs(nums[i]);
           
            if(nums[index-1]<0){
                // nums[k++]= index;
                res.push_back(index);
            }else
            nums[index-1]*=-1;
            
        }
       
       
        
        // return vector<int> (nums.begin(), nums.begin()+k);
        
        return res;
    }
};