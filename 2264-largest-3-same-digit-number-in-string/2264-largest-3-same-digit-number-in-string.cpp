class Solution {
public:
    string largestGoodInteger(string num) {
        int i=0;
        int ans=-1;
        string maxi="";
        while(i+2<num.size()){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                int n= (num[i]-'0')*100 + (num[i+1]-'0')*10 + (num[i+2]-'0');
                string cur="";
                cur+= num[i];
                cur+= num[i+1];
                cur+= num[i+2];
              
                if(n>ans){
                    maxi= cur;
                    ans=n;
                }
                i+=3;
               
            }else
            i++;
        }
        return maxi;
    }
};