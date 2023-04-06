class Solution {
    private:
//     void makeZero(int *hash, string& str, char c){
//         int ct=1;
//         int index= (int)c;
//         hash[index]=0;
//         int i=0;
//         while(str[i]!=c){
//             index= (int)str[i];
//             hash[index]=0;
//             ct++;
//             i++;
//         }
//        str.erase(0,ct);
//         return;
//     }

//    int solution1(string s){
    //O(n^2) time complexity and O(n) auxilary-space---
//           int hash[256]={0};
//         string str;
//         int res=0;
//         for(int i=0; i<s.size(); i++){
//             int index= (int)s[i];
//             if(hash[index]==0){
//             hash[index]=1;
//             str.push_back(s[i]);
//             }else{
//                     makeZero(hash,str,s[i]);
//                     str.push_back(s[i]);
//                     hash[index]=1;
//             }
//             int x= str.size();
//             res= max(res,x);
//          }
        
//         return res;
//     }

int solution2(string s){//solving sliding window method using hashmap as sliding window--- t.c:- O(2*n)=(n) & auxilary-space:- O(min(n,sizeof(charSet)))--
    map<char,int> m;
    int res=0;
    int left=0, right=0;
    while(right<s.size()){
        char r= s[right];
        m[r]++;
        
        while(m[r]>1){
            char l= s[left];
            m[l]--;
            left++;
        }
        res= max(res,right-left+1);
        right++;
    }

    return res;
}
public:
    int lengthOfLongestSubstring(string s) {
    //  return solution1(s);
      return solution2(s);
    }       
};