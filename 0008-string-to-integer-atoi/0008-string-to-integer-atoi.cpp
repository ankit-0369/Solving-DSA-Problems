class Solution {
private:
void solve(string s, int i, int &ans, bool &neg){
    if(i==s.size()){
        return;
    }
         if(s[i]>='0' && s[i]<='9'){
        if(ans>INT_MAX/10){
            if(neg==true){
                ans= INT_MIN;
                neg= false;
                return;
            }
           ans= INT_MAX;
           return;
        }else if(ans==INT_MAX/10){
            if((s[i]-'0')>7 && neg==false){
                      ans= INT_MAX;
                      return;
                   }else if(s[i]-'0'>7 && neg==true){
                            ans= INT_MIN;
                            neg= false;
                            return;
                   }
        }
        ans= ans*10+ (s[i]-'0');
    }else if(i!=0){
        return;
    }
    solve(s,i+1, ans,neg);

}

int solveUsingRecursion(string s){
        if(s[0]!=' ' && s[0]!='-' && s[0]!= '+' && (s[0]<'0' || s[0]>'9') ){
            return 0;
        }

        int ans=0;
        int i=0;
        bool neg= false;
        
         while(i<s.size()){
            if(s[i]==' '){
                i++;
            }else if(s[i]=='-' || s[i]=='+'){
              if(s[i]=='-'){
                  neg=true;
              }
                i++;
                break;
            }else{
                break;
            }

        }
        solve(s,i,ans,neg);
        if(neg){
            return -1*ans;
        }
    
      

        return ans;
}

int solveUsingIteration(string s){
       
         int i=0;
        int ans= 0;
        bool neg= false;
        while(i<s.size()){
            if(s[i]==' ' && !(s[i]>='0' && s[i]<='9')){
                i++;
            }else if(s[i]=='-' || s[i]=='+'){
              if(s[i]=='-'){
                  neg=true;
              }
                i++;
                break;
            }else
               break;

        }
        
    while(s[i]!='\0'){
            if(s[i]>='0' && s[i]<='9'){
               //positive case
               if(ans>INT_MAX/10){
                   if(neg){
                       return INT_MIN;
                   }
                return INT_MAX;
               }else if(ans== INT_MAX/10){
                   if((s[i]-'0')>7 && neg==false){
                       return INT_MAX;
                   }else if(s[i]-'0'>7 && neg==true){
                            return INT_MIN;
                   }
                   
                  
               }

             //negative case---

            ans= ans*10 + (s[i]-'0');

            }else
              break;

            i++;
        }
        
         if(neg){
            ans*= -1;
        }
        return ans;

}

public:
    int myAtoi(string s) {

         // return solveUsingRecursion(s);


            return solveUsingIteration(s);
    }
};