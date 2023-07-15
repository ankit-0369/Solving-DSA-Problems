class Solution {
    int validParenthesesCnt(string s){
        stack<char> st;
        int cnt=0;
        for(auto ch:s){
            if(ch== '('){
                st.push(ch);
            }else{
                if(!st.empty()){
                    //ch-->')' && st.top---> '('
                    st.pop();
                    cnt++;
                }
            }
        }

        return 2*cnt;
    }
public:
    int minAddToMakeValid(string s){
    int cnt=0;
    int n= s.size();
    int cntValid= validParenthesesCnt(s);

    return (n-cntValid);  
    }    
};