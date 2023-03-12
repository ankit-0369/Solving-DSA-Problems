class Solution {

bool isvowel(char c){
   
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
        return true;
    }

    return false;
}

public:
    int vowelStrings(vector<string>& w, int left, int right) {
        int ct=0;
        int i=left;
        for(; i<=right; i++){
               
               int j= w[i].size()-1;
            if(isvowel(w[i][0]) ==true && isvowel(w[i][j])==true){
                ct++;
            }
        }

            return ct;
    }
};