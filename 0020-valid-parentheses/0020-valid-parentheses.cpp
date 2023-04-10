class Solution {
    private:
//     bool solve1(string s){
//                stack<char> st;
//        for(auto c:s){
//            if(c=='(' || c=='{' || c=='['){
//                st.push(c);
//            }else{
//                if(st.empty() || (c==')' && st.top()!='(')||(c=='}' && st.top()!='{') || (c==']' && st.top()!='[') )
//                return false;
//                st.pop();
//            }
//        }

//        return st.empty();
//     }
    bool solve2(string s){
        vector<char> st;
        for(auto c: s){
            if(c=='(' or c=='{' or c=='['){
                st.push_back(c);
            }else{
                if(st.empty() or (st[st.size()-1]=='(' and c!=')') or (st[st.size()-1]=='{' and c!='}') or (st[st.size()-1]=='[' and c!=']'))
                return false;
                st.pop_back();
            }
        }
        return st.empty();
    }
public:
    bool isValid(string s) {//t.c:- O(n) &  auxilary-space:- O(n)--------
            // return solve1(s);
        return solve2(s);
    }
};