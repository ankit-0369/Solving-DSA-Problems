class Solution {
public:
    vector<int>  nextSmallerElement(vector<int> p){
        vector<int> ans;
        stack<int> st;
        st.push(0);
        for(int i=p.size()-1; i>=0; i--){
            int ele= p[i];
            while(st.top()>ele && st.size()>1){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(ele);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<int> finalPrices(vector<int>& p) {
        //naive approach---use nextSmallerElement then find the ans---
        vector<int> nextSmall= nextSmallerElement(p);
        vector<int> ans;
        for(int i=0; i<p.size(); i++){
            int x= p[i]-nextSmall[i];
            ans.push_back(x);
        }

        return ans;
    }
};