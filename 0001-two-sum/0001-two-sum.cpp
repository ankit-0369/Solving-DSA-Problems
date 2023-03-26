class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
       map<int,int> m;
       
        for(int i=0; i<nums.size(); i++){  //O(nlogn) as m.find() search in logn t.c.
            int val= target-nums[i];
            if(m.find(val)!=m.end()){
                return {m[val],i};
            }else
            m.insert({nums[i],i});
        }
        return {};
    }
};