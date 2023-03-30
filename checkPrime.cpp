#include<bits/stdc++.h>

using namespace std;

int main(){
 int n;
 cin>>n;
int fact=1;
for(int i=2; i<n; i++){
    fact*= i;
}
if((fact)%n==n-1){
    cout<<"prime\n";
}else
cout<<"not a prime\n";

return 0;
}