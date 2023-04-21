class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int ct=0;
        int index[2]={-1,-1};
        int k=0;
       for(int i=0; i<s1.size(); i++){
           if(s1[i]!=s2[i]){
               if(k==2)
                   return false;
              index[k++]= i;
           }
         
         }
          if(k==1)
          return false;
          if(k==2){
              if(s1[index[0]]==s2[index[1]] && s2[index[0]]==s1[index[1]]){
                  return true;
              }else
              return false;
          }

          return true;

    }
};