class Solution {
public:
    bool checkString(string s) {
        /*brute force t.c:- O(nlogn) & auxilary -space:- O(1)
        string r=s;
        sort(r.begin(),r.end());
        if(s==r){
            return true;
        }

        return false;
        */
        //t-c:- O(n) & auxilary-space:- O(1)
              
        for(int i=0; i+1<s.size(); i++){
            if(s[i]=='b' && s[i+1]=='a'){
               return false;
            }
        }
       
        return true;
    }
};