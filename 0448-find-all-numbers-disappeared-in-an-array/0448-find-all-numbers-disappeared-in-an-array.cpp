class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ct(nums.size()+1,0);
        for(int i=0; i<nums.size(); i++){

            ct[nums[i]]++;
        }
        vector<int> res;
        for(int i=1; i<ct.size(); i++){

            if(ct[i]==0)
                res.push_back(i);
                
        }
        
        return res;
        
    }
};