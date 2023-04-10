class Solution {
public:
    bool isValid(string s) {//t.c:- O(n) &  auxilary-space:- O(n)--------
       stack<char> st;
       for(auto c:s){
           if(c=='(' || c=='{' || c=='['){
               st.push(c);
           }else{
               if(st.empty() || (c==')' && st.top()!='(')||(c=='}' && st.top()!='{') || (c==']' && st.top()!='[') )
               return false;
               st.pop();
           }
       }

       return st.empty();
    }
};