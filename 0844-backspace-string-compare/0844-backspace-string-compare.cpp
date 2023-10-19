class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(auto ch: s){
            if(ch=='#' && !s1.empty()){
                s1.pop();
            }else if(ch!= '#')
            s1.push(ch);
        }

        for(auto ch: t){
            if(ch=='#' && !s2.empty()){
                s2.pop();
            }else if(ch!= '#')
            s2.push(ch);
        }

        return s1==s2;


    }
};