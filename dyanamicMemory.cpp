#include<bits/stdc++.h>

using namespace std;

int main(){
 int* p= new int[5];
 for(int i=0; i<5; i++){
    cin>>p[i];
 }
sort(p, p+5);
 for(int i=0; i<5; i++){
    cout<<p[i]<<"\t";
    // delete[] p;
 }
 delete [] p;
 cout<<endl;
 cout<<p[4]<<endl;
return 0;
}