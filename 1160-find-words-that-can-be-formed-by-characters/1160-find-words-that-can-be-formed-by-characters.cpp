class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        int hash[26]= {0};
        for(auto ch: chars){
            hash[ch-'a']++;
        }
        for(auto word:words){
           int hash2[26]={0};
            bool check=true;
            for(auto ch:word){
                hash2[ch-'a']++;
                if(hash2[ch-'a']>hash[ch-'a']){
                    check= false;
                    break;
                }
            } 
            if(check)
                ans+= word.size();
            
        }
        return ans;
    }
};