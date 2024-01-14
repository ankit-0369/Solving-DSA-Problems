class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> hash1(26,0), hash2(26,0);
        set<char> s1, s2;
        for(auto ch: word1){
            hash1[ch-'a']++;
            s1.insert(ch);
        }
        for(auto ch:word2){
            hash2[ch-'a']++;
            s2.insert(ch);
        }
    sort(hash1.begin(), hash1.end());
    sort(hash2.begin(), hash2.end());
    return (word1.size()== word2.size() && s1==s2 && hash1==hash2);

    }
};