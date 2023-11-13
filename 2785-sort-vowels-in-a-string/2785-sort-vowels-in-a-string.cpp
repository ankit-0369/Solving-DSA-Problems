class Solution {
public:
    bool isVowel(char ch){
        
            return (ch=='A' || ch=='E'|| ch=='I'|| ch=='O' || ch=='U' ||
            ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u'
            );
    }
    string sortVowels(string s) {
        // vector<char> vow;
        // for(int i=0; i<s.size(); i++){
            
        //     if(s[i]=='A' || s[i]=='a' || s[i]=='E' || s[i]=='e' || s[i]=='I' || s[i]=='i' || s[i]=='O' || s[i]=='o' || s[i]=='U' || s[i]=='u'){
        //         vow.push_back(s[i]);
        //         s[i]='#';
                
        //     }
        // }
        
        // sort(vow.begin(), vow.end());
        // int j= 0;
        // for(int i=0; i<s.size(); i++){
            
        //     if(s[i]=='#'){
        //         s[i]= vow[j++];
        //     }
        // }
        
        // return s;
        string sortedVowel= "AEIOUaeiou";
        int cur=0;
        map<char, int> m;
        for(auto ch: s){
            if(isVowel(ch)){
                m[ch]++;
            }
        }

        string ans;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                // s[i]= sortedVowel[cur];
                // m[sortedVowel[cur]]--;
                // if(m[sortedVowel[cur]]==0) cur++;

                while(m[sortedVowel[cur]]==0) cur++;
                s[i]= sortedVowel[cur];
                m[sortedVowel[cur]]--;
            }
        }

        return s;
    }
};