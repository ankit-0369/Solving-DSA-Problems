class Solution {
public:
    int solve(int ind1, int ind2, string s, string t, vector<vector<int>>& memo){
        if(ind2<0 ) return 1;
        if(ind1<0) return 0;
        
        if(memo[ind1][ind2]!= -1) return memo[ind1][ind2];
        
        
        if(s[ind1]== t[ind2])
            return memo[ind1][ind2]= solve(ind1-1, ind2-1, s,t, memo) + solve(ind1-1, ind2, s,t, memo);
        
        //else case means we have one option only to go down in s and check for match with t's charcater.
        return memo[ind1][ind2]= solve(ind1-1, ind2, s,t, memo);
        
        
    }
    int numDistinct(string s, string t) {
        int n= s.size();
        int m= t.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return solve(n-1, m-1, s,t, memo);
    }
};