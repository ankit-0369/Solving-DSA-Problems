class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int i=0, j=0;
        int ct=1;
        while(i<max(word1.size(), word2.size())){
            if(i<word1.size())
            merged.push_back(word1[i]);
            if(i<word2.size())
            merged.push_back(word2[i]);
            i++;
        }
    

        return merged;
    }
};