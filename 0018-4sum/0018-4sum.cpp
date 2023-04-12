class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {// t.c:-O(n3) & auxilary-space:- O(n)
        vector<vector<int>> res;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
               long long toFind= (long long)target-((long long)nums[i]+ (long long)nums[j]);
                int left= j+1;
                int right= n-1;
                while(left<right){
                    if(nums[left]+ nums[right]==toFind){
                            s.insert({nums[i],nums[j],nums[left], nums[right]});
                            left++, right--;
                    }else if(nums[left]+ nums[right]>toFind)
                    right--;
                    else
                    left++;
                }
            }
        }
        for(auto v: s){
            res.push_back(v);
        }
        return res;
    }
};