#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string s,int i){
    if(s.size()-i-1==0)
    return true;
    if(s[i]==s[s.size()-i-1]){
        checkPalindrome(s,i+1);
    }else
    return false;
}

int main(){
 string s;
 cin>>s;
 int i=0;
if(checkPalindrome(s,i))
cout<<1;
else
cout<<0;
return 0;
}