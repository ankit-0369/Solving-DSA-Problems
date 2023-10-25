class Solution {
public:
    
    int solve(vector<int>& nums, bool lastTake){
        int n= nums.size();
        int s= (lastTake==true) ? 1:0;
        int e= (lastTake==true)? n : n-1;
        int prev2= 0, prev1= nums[s];
        for(int i=s; i<e; i++){
            int cur= nums[i];
            if(i>s+1) cur+= prev2;
            cur= max(cur, prev1);
            prev2= prev1;
            prev1= cur;
            
        }
        return prev1;
    }
    
    long long int maxSum(vector<int> &nums){
    int n= nums.size();
    int prev1= nums[0], prev2= 0;//base case prev2 is dp[i-2] prev1 dp[i-1]
    for(int i=0; i<n; i++){
        int cur= nums[i];
        if(i>1) cur+= prev2;
        cur= max(prev1, cur);
        prev2= prev1;
        prev1= cur;

    }

    return prev1;
}
    
    int rob(vector<int>& nums) {
        
            if(nums.size()==1) return nums[0];
        int ansWithoutLast= solve(nums, false);
       
        int ansWithLast= solve(nums, true);
        return max(ansWithLast, ansWithoutLast);
//         int n=nums.size();
//         vector<int> temp1, temp2;
//         for(int i=0; i<n; i++)
//         {
//             if(i!=0) temp1.push_back(nums[i]);
//             if(i!=n-1) temp2.push_back(nums[i]);
//         }
        
//         return max(maxSum(temp1), maxSum(temp2));
    }
};