class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0, j=0,k=0;
        while(i<pushed.size() || j<popped.size()){//t.c:- O(n) && auxilary-space:- O(n)
            if(st.empty() && i<pushed.size()){
                // cout<<"push: "<<pushed[i]<<"\n";
                st.push(pushed[i]);
                i++;
            }
            if( !st.empty() && st.top()==popped[j]){
                // cout<<"pop: "<<st.top()<<"\n";
                st.pop();
                j++;
            }else if(!st.empty() && st.top()!= popped[j] && i<pushed.size()){
                // cout<<"push: "<<pushed[i]<<"\n";
                st.push(pushed[i]);
                i++;
            }else{
               break;
            }
        }
     return st.empty();
    }
};