class Solution {
public:
    string removeStars(string s) {//t.c:- O(n) and Auxilary-space:- O(n)
        vector<char> st;
        for(auto c:s){
            if(c!='*'){
                st.push_back(c);
            }else{
                if(!st.empty()){
                    st.pop_back();
                }
            }
        }
        s.clear();
       
    for(auto c:st){
        s.push_back(c);
    }
        return s;
    }
};