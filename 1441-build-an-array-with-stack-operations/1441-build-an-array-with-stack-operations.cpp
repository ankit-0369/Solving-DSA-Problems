class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        
       int cur=0;
        int i=1;
        while(i<=n && cur<target.size()){
            if(target[cur]== i){
                ans.push_back("Push");
                i++;
                cur++;
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
                i++;
            }
        }
        
        return ans;
    }
};