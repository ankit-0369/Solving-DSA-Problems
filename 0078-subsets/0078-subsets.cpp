class Solution {
private:
   void solve(vector<int> &nums, int i, vector<int> sub, vector<vector< int> > &ans){
       //base case
        if(i>=nums.size()){
            ans.push_back(sub);
            return;
        }
        //working
       
         solve(nums,i+1, sub, ans);
         
       sub.push_back(nums[i]);
      
       solve(nums,i+1, sub, ans);
       
       // sub.pop_back();
       
       
         
    }
    
    public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<int > sub;
        vector<vector<int> > ans;
        solve(nums, i, sub, ans);
        
        return ans;
    }
};