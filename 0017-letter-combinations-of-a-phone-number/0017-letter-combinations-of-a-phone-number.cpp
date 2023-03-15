class Solution {
    private:

        void solve(string dig, string cur, int i, vector<string> & ans, vector<string> m){

            if(i==dig.length()){
               cout<<cur<<" ";
                ans.push_back(cur);
                return;
            }
            int j=0;
            int num= dig[i]-'0';
            while(j<m[num].size())
           {
                char c= m[num][j++];
            cur.push_back(c);
            solve(dig,cur,i+1,ans,m);
            cur.pop_back();
           }
           
            
        }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){

            return {};
        }
        vector<string> ans;
        string cur;
        vector<string> mapped= {"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            int i=0;
        solve(digits, cur, i, ans, mapped);

        return ans;
    }
};