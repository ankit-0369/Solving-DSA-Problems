class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26,0), b(26,0);
        for(auto ch:s) a[ch-'a']++;
        for(auto ch:t) b[ch-'a']++;
        return a==b;
    }
};